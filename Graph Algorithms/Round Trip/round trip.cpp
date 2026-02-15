#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5;
 
int n, m, CycleNode, Node;
bool seen[NMAX];
int up[NMAX];
vector<int> g[NMAX];
 
bool bfs(int node, int parent) {
    seen[node] = 1;
    up[node] = parent;
    for(int son : g[node]) {
        if(son == parent) continue;
        if(seen[son]) {
            CycleNode = son;
            Node = node;
            return 1;
        }
        if(bfs(son, node)) return 1;
    }
    return 0;
}
 
bool FoundCycle() {
    for(int node = 1; node <= n; node++) 
        if(!seen[node] && bfs(node, node))
            return 1;
    return 0;
}
 
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(!FoundCycle()) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
 
 
    vector<int> ans;
    ans.push_back(CycleNode);
    int aux = Node;
    while(aux != CycleNode) {
        ans.push_back(aux);
        aux = up[aux];
    }
    ans.push_back(CycleNode);
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    puts("");
	
    return 0;
}
