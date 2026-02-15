#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int NMAX = 2e5;

int n, m;
int InDegree[NMAX];
bool seen[NMAX];

vector<int> g[NMAX];

int main() {
    scanf("%d %d", &n ,&m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        InDegree[y]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!InDegree[i])
            q.push(i);
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int son : g[node]) {
            InDegree[son]--;
            if(!InDegree[son]) q.push(son);
        }
        ans.push_back(node);
    }
    if(ans.size() != n) {
        puts("IMPOSSIBLE");
        return 0;
    }
    for(int course : ans) printf("%d ", course);

    puts("");


    return 0;
}
