#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 2e5;

int n, m;
bool seen[NMAX];
vector<int> g[NMAX];
vector<int> backedge[NMAX];

void dfs(int node, vector<int> *g) {
    seen[node] = 1;
    for(int son : g[node]) {
        if(seen[son]) continue ;
        dfs(son, g);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        backedge[y].push_back(x);
    }
    dfs(1, g);
    for(int node = 1; node <= n; node++) {
        if(seen[node]) continue;
        printf("NO\n1 %d\n", node);
        return 0;
    }
    for(int node = 1; node <= n; node++) seen[node] = 0;
    dfs(1, backedge);
    for(int node = 1; node <= n; node++) {
        if(seen[node]) continue;
        printf("NO\n%d 1\n", node);
        return 0;
    }
    printf("YES\n");

    return 0;
}
