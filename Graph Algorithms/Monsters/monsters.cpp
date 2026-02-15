#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 1003;
 
int n, m, x, y, dist[NMAX][NMAX];
char mat[NMAX][NMAX];
queue<pair<int, int>> q;
string moves, ans;
 
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char sign[4] = {'U', 'R', 'D', 'L'};
 
bool CanTravel(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m && mat[x][y] != '#';
}
 
void bfs_monster() {
    while(!q.empty()) {
        pair<int, int> monster = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int newx = monster.first + dx[dir];
            int newy = monster.second + dy[dir];
			
            if(CanTravel(newx, newy) && dist[monster.first][monster.second] + 1 < dist[newx][newy]) {
                q.push({newx, newy});
                dist[newx][newy] = dist[monster.first][monster.second] + 1;
            }
        }
    }
}
 
bool Border(int x, int y) {
    return x == 1 || x == n || y == 1 || y == m;
}
void dfs(int x, int y) {
    if(Border(x, y)) {
        ans = moves;
    }
    for(int dir = 0; dir < 4; dir++) {
        int newx = x + dx[dir];
        int newy = y + dy[dir];
        if(CanTravel(newx, newy) && dist[x][y] + 1 < dist[newx][newy]) {
            dist[newx][newy] = dist[x][y] + 1;
            moves.push_back(sign[dir]);
            dfs(newx, newy);
            moves.pop_back();
        }
    }
}
 
int main() {
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            dist[i][j] = INT_MAX;
            scanf(" %c", &mat[i][j]);
            if(mat[i][j] == 'M') q.push({i, j}), dist[i][j] = 0;
            else if(mat[i][j] == 'A') x = i, y = j;
        }
 
    if(Border(x, y)) {
        printf("YES\n0");
        return 0;
    }
    bfs_monster();
    dist[x][y] = 0;
    dfs(x, y);
 
    if(ans.size() > 0) {
        printf("YES\n%d\n", (int)ans.size());
        for(auto c : ans)
            printf("%c", c);
        puts("");
    } else {
        puts("NO");
    }
	
    return 0;
}
