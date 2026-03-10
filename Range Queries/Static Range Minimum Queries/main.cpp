#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
	int n, q;
    cin >> n >> q;
 
    vector<vector<int>> rmq(n + 1, vector<int>(32, 0));
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        rmq[i][0] = val;
    }
 
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 1; i <= n - (1 << j) + 1; i++) {
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
 
    while(q--) {
        int x, y;
        cin >> x >> y;
        int diff = y - x, lg = 0;
        while(diff >>= 1) {
            lg++;
        }
        cout << min(rmq[x][lg], rmq[y - (1 << lg) + 1][lg]) << '\n';;
    }
    
}
