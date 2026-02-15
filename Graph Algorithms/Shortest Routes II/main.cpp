#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll INF = 1e18;
 
int n, m, q;
int main()
{
    scanf("%d %d %d", &n, &m, &q);
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    for(int i = 1; i <= m; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        if(c < dp[x][y])dp[x][y] = dp[y][x] = c;
    }
    for(int k = 1; k <= n; k++) {
        for(int  i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                dp[i][j]  = dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x == y) dp[x][y] = 0;
        if(dp[x][y] == INF) puts("-1");
        else printf("%lli\n", dp[x][y]);
    }
    return 0;
}
