#include <bits/stdc++.h>

using namespace std;

/* We'll use segment tree with lazy propagation
 * The lazy information contained in each node is the following:
 *  - the starting value of the arithmetic progression
 *  - the pace of the arithmetic progression
 *
 * The key observation is how the update affects the node:
 * Adding another arithmetic progression of pace 1 increases the arithmetic progression
 * already in place in that interval [l, r] by 1 !!!
 * 
 * Example:    1 2 3 -> pace 1         
 *             4 5 6 -> pace 1
 *             ----- (+)
 *             5 7 9  -> pace 2
 */

class Segtree {
private:

    /*  t[node].sum = the sum in the node
     *  t[node].lazy = the value at which the arithmetic progression stars in the interval [l, r]
     *  t[node].offset = the pace of the arithmetic progression in the itnerval [l, r]
     */

    struct Node { long long sum = 0, lazy = 0, offset = 0; };

    int N;
    vector<Node> t;

public:

    Segtree(const vector<int> &vals) : N((int)vals.size() - 1) {
        t.resize(4 * N);
        build(1, 1, N, vals);
    }

    void build(int node, int l, int r, const vector<int> &vals) {
        if (l == r) {
            t[node].sum = vals[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, vals);
        build(2 * node + 1, mid + 1, r , vals);
        t[node].sum = t[2 * node].sum + t[2 * node + 1].sum;
    }

    // Lazy propagation
    void push(int node, int l, int r) {
        if (t[node].offset == 0) { return; }
        // Update the sum in the node by adding the arithmetic progression
        t[node].sum += 1LL * (r - l + 1) * (2 * t[node].lazy + (r - l) * t[node].offset) / 2;
        // Avoid leaf nodes for overflowing
        if (l != r) {
            int mid = (l + r) / 2;
            t[2 * node].lazy += t[node].lazy;
            t[2 * node + 1].lazy += t[node].lazy + (mid - l + 1) * t[node].offset;
            t[2 * node].offset += t[node].offset;
            t[2 * node + 1].offset += t[node].offset;
        }
        // Emtpy the lazy information in node
        t[node].lazy = t[node].offset = 0;
    }

    void update(int node, int l, int r, int x, int y) {
        push(node, l, r);
        if (r < x || l > y) { return; }
        if (x <= l && r <= y) {
            // Add at the start of the arithmetic progression the distance to the l
            t[node].lazy += l - x + 1;
            // Increase the pace of the arithmetic progression
            t[node].offset++;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, x, y);
        update(2 * node + 1, mid + 1, r , x, y);
        t[node].sum = t[2 * node].sum + t[2 * node + 1].sum;
    }

    long long query(int node, int l, int r, int x, int y) {
        push(node, l, r);
        if (r < x || l > y) { return 0; }
        if (x <= l && r <= y) { return t[node].sum; }
        int mid = (l + r) / 2;
        long long answer_left = query(2 * node, l, mid, x, y);
        long long answer_right = query(2 * node + 1, mid + 1, r, x, y);
        return answer_left + answer_right;
    }

};

int main() {

    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    Segtree st(v);
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            st.update(1, 1, n, x, y);
        } else {
            cout << st.query(1, 1, n, x, y) << '\n';
        }
    }

    return 0;
}
