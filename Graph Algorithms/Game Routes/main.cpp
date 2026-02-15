#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 2e5;
const int MOD = 1e9+7;
int n, m;
int InDegree[NMAX], dp[NMAX];
vector<int> g[NMAX];
vector<int> backedge[NMAX];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        backedge[y].push_back(x);
        InDegree[y]++;
    }

    // Kahn's algorithm for topological sort
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!InDegree[i])
            q.push(i);
    }
    dp[1] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int son : g[node]) {
            InDegree[son]--;
            if(!InDegree[son]) q.push(son);
        }
        for(int prev : backedge[node]) {
            dp[node] = (dp[node] + dp[prev]) % MOD;
        }
    }
    printf("%d\n", dp[n]);

    return 0;
}
