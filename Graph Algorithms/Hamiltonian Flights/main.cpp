#include <bits/stdc++.h>

using namespace std;

const int NMAX = 20;
const int MOD = 1e9 + 7;

int n, m;
int dp[NMAX][1 << NMAX];
vector<vector<int>> g;

int main() {
    cin >> n >> m;
    g.resize(n);
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
    }

    dp[0][1] = 1;

    for(int mask = 2; mask < (1 << n); mask++) {
        if(!(mask & 1)) { continue; }
        if(mask != (1<<n)-1 && (mask & (1 << (n-1)))) { continue; }
        for(int node = 0; node < n; node++) {
            if((mask & (1 << node)) == 0) { continue; }
            int diff_mask = mask - (1 << node);
            for(int parent : g[node]) {
                if(mask & (1 << parent)) {
                    dp[node][mask] = (dp[node][mask] + dp[parent][diff_mask]) % MOD;
                }
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1];

    return 0;
}
