#include <bits/stdc++.h>

using namespace  std;

const int NMAX = 503;

int n, m, k;
int match[2 * NMAX];
bool seen[2 * NMAX];
vector<int> g[NMAX];

bool mbm(int boy) { // Maximum Bipartite Match
    for(auto girl : g[boy]) {
        if(seen[girl]) continue;
        seen[girl] = true;
        if(!match[girl] || mbm(match[girl])) {
            match[girl] = boy;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
    }

    int ans = 0;
    for(int node = 1; node <= n; node++) {
        for(int i = 1; i <= m; i++) seen[i] = 0;
        if(mbm(node)) ans++;
    }

    printf("%d\n", ans);
    for(int girl = 1; girl <= m; girl++) {
        if(!match[girl]) continue;
        printf("%d %d\n", match[girl], girl);
    }

    return 0;
}
