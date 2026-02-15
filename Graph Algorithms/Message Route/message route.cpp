#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5;
 
int n, m;
int parent[NMAX];
bool seen[NMAX];
vector<int> g[NMAX];
 
 
void bfs(int start) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int son : g[node]) {
            if(seen[son]) continue;
            seen[son] = 1;
            parent[son] = node;
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
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
    bfs(1);
	
    vector<int> ans;
    int aux = n;
    while(aux != 1) {
        ans.push_back(aux);
        aux = parent[aux];
        if(aux == - 1) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    ans.push_back(1);
    printf("%d\n", (int)ans.size());
    for(int i = ans.size()-1; i >= 0; i--)
        printf("%d ", ans[i]);
    printf("\n");
	
    return 0;
}
