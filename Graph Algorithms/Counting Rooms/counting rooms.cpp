#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 1003;
 
int n, m;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool viz[NMAX][NMAX];
char v[NMAX][NMAX];
 
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
			if(inside(newx,newy) && v[newx][newy] == '.' && !viz[newx][newy]) {
				viz[newx][newy] = 1;
				q.push({newx,newy});
			}
		}
	}
}
 
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> v[i][j];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(v[i][j] == '.' && !viz[i][j]) {
				cnt++;
				dfs(i,j);
			}
		}
	cout << cnt << '\n';
	
	return 0;
}
