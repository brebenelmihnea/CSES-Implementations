#include <iostream>
 
using namespace std;
 
const int NMAX = 1003;
 
int n, q;
bool mat[NMAX][NMAX];
 
class fenwick_tree {
private:
    int t[NMAX][NMAX];
    int lsb(int x) { return (x & (-x)); }
public:
    void update(int x, int y, int val) {
        for(int i = x; i <= n; i += lsb(i)) {
            for(int j = y; j <= n; j += lsb(j)) {
                t[i][j] += val;
            }
        }
    }
    int get_trees(int a, int b) {
        int ans = 0;
        for(int i = a; i >= 1; i -= lsb(i)) {
            for(int j = b; j >= 1; j -= lsb(j)) {
                ans += t[i][j];
            }
        }
        return ans;
    }
    int get_trees(int a, int b, int x, int y) {
        return get_trees(x, y) - get_trees(a-1, y) - get_trees(x, b-1) + get_trees(a-1, b-1);
    }
}bit;
 
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if(ch == '*') {
                bit.update(i, j, 1);
                mat[i][j] = true;
            }
        }
    }
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x, y;
            cin >> x >> y;
            bit.update(x, y, (mat[x][y] ^ 1) ? 1 : -1);
            mat[x][y] = mat[x][y] ^ 1;
        } else {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            cout << bit.get_trees(a, b, x, y) << '\n';
        }
    }
    
    return 0;
}
