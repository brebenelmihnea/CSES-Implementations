#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1003;

int n, m;
int xa, ya;
int xb, yb;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char v[NMAX][NMAX];
int step[NMAX][NMAX];
bool viz[NMAX][NMAX];
int d[NMAX][NMAX];
string manta = "URDL";

bool inside(int x,int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dfs(int a,int b) {
    queue<pair<int,int>> q;
    q.push({a,b});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int newx = x + dx[dir];
            int newy = y + dy[dir];
            if(inside(newx,newy) && v[newx][newy] != '#' && !viz[newx][newy]) {
                viz[newx][newy] = 1;
                d[newx][newy] = d[x][y] + 1;
                step[newx][newy] = dir;
                q.push({newx,newy});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'A')
                xa = i, ya = j;
            if(v[i][j] == 'B')
                xb = i, yb = j;
        }
    dfs(xa,ya);
    if(d[xb][yb] == 0)
        cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        cout << d[xb][yb] << '\n';
        vector<int> path;
        int x = xb, y = yb;
        while(x != xa || y != ya) {
            int aux = step[x][y];
            x = x - dx[aux];
            y = y - dy[aux];
            path.push_back(aux);
        }
        for(int i = path.size()-1; i >= 0; i--)
            cout << manta[path[i]] ;
        cout << '\n';
    }


    return 0;
}
