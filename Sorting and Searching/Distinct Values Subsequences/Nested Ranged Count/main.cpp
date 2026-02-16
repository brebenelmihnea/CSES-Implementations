#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct interval {
    int x, y, idx;
    bool operator<(const interval &i) const {
        return x < i.x || (x == i.x && y > i.y);
    }
};
 
class FenwickTree {
private:
    vector<int> t;
    int lsb(int num) { return -num&num; }
public:
    FenwickTree(int n) : t(n + 1) {}
    void clear() { fill(t.begin(), t.end(), 0); }
    void update(int idx, int val) {
        for (int i = idx; i < t.size(); i += lsb(i)) {
            t[i] += val;
        }
    }
    int query(int idx) {
        int cnt = 0;
        for (int i = idx; i > 0; i -= lsb(i)) {
            cnt += t[i];
        }
        return cnt;
    }
};
 
int main() {
 
    int n;
    cin >> n;
 
    map<int, int> mp;
    vector<interval> intervals;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y, i});
        mp[x] = mp[y] = 0;
    }
 
    sort(intervals.begin(), intervals.end());
 
    int id = 0;
    for (auto &x : mp) {
        x.second = ++id;
    }
 
    FenwickTree ft(2 * n);
    vector<int> contains(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        int y = mp[intervals[i].y], idx = intervals[i].idx;
        contains[idx] = ft.query(y);
        ft.update(y, 1);
    }
 
    ft.clear();
 
    vector<int> contained(n + 1);
    for (int i = 0; i < n; i++) {
        int y = mp[intervals[i].y], idx = intervals[i].idx;
        contained[idx] = i - ft.query(y - 1);
        ft.update(y, 1);
    }
 
    for (int i = 1; i <= n; i++) { cout << contains[i] << ' '; }
    cout << '\n';
    for (int i = 1; i <= n; i++) { cout << contained[i] << ' '; }
 
    return 0;
}
