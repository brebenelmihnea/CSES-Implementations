#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	const int MAXN = 1e6;
	const int INF = 1e9;
	const int MAXLOG = 21;
 
	int n, q;
	cin >> n >> q;
 
	vector<int> end(MAXN + 5, INF);
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		end[x] = min(end[x], y);
	}
 
	vector<int> nxt(MAXN + 5);
	nxt[MAXN + 1] = INF;
	for (int i = MAXN; i >= 0; i--) {
		nxt[i] = min(nxt[i + 1], end[i]);
	}
 
	vector<vector<int>> up(MAXN + 5, vector<int>(MAXLOG, 0));
	for (int i = 0; i <= MAXN; i++) {
		up[i][0] = nxt[i];
	}
 
	for(int j = 1; j < MAXLOG; j++) {
		for(int i = 1; i <= MAXN; i++) {
			int mid = up[i][j - 1];
			up[i][j] = (mid <= MAXN ? up[mid][j - 1] : INF);
		}
	} 
	
	while (q--) {
		int l, r, ans = 0;
		cin >> l >> r;
		for (int i = MAXLOG - 1; i >= 0; i--) {
			int next_film = up[l][i];
			if (next_film <= r) {
				ans += (1 << i);
				l = next_film;
			}
		}
		cout << ans << '\n';
	}
 
	return 0;
}
