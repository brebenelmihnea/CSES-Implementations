#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2e5;

int n, m;
bool color[NMAX], seen[NMAX], impossible;
vector<int> g[NMAX];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    seen[start] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int son : g[node]) {
            if(seen[son] && color[son] == color[node]) {
                impossible = 1;
                return ;
            } else if(seen[son]) {
                continue ;
            }
            seen[son] = 1;
            color[son] = color[node] ^ 1;
            q.push(son);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if(!seen[i]) bfs(i );
    }
    if(impossible) {
        puts("IMPOSSIBLE");
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", color[i] + 1);
    }
    puts("");

    return 0;
}
