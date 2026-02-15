#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 2e5;

int n, m, SCC;
int v[NMAX], comp[NMAX];
ll dp[NMAX], group[NMAX];
bool viz[NMAX];

vector<int> g[NMAX], rg[NMAX], t[NMAX];
stack<int> st;

void dfs(int node) {
    viz[node] = 1;
    for(int son : g[node]) {
        if(viz[son]) continue;
        dfs(son);
    }
    st.push(node);
}

ll dfs2(int node) {
    if(dp[node]) return dp[node];
    dp[node] = group[node];
    for(int son : t[node])
        dp[node] = max(dp[node], dfs2(son) + group[node]);
    return dp[node];
}

void dfsr(int node) {
    comp[node] = SCC;
    for(int son : rg[node]) {
        if(comp[son]) continue;
        dfsr(son);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
        if(!viz[i])
            dfs(i);

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(comp[node]) continue;
        SCC++;
        dfsr(node);
    }

    for(int i = 1; i <= n; i++)
        group[comp[i]] += v[i];
    for(int i = 1; i <= n; i++) {
        for(int neighbour : g[i]) {
            if(comp[i] == comp[neighbour]) continue;
            t[comp[i]].push_back(comp[neighbour]);
        }
    }

    ll ans = 0;
    for(int i = 1; i <= SCC; i++)
        ans = max(ans, dfs2(i));
    printf("%lli\n", ans);

}
