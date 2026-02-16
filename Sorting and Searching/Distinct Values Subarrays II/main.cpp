#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 3e5;
 
int n, k;
int v[NMAX];
map<int, int> m;
 
int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &v[i]);
	int r = 1, dist = 0;
	long long ans = 0;
	for(int l = 1; l <= n; l++) {
		while(r <= n && dist + (m[v[r]] == 0) <= k) {
			dist += (m[v[r]] == 0);
			m[v[r]]++;
			r++;
		}
		m[v[l]]--;
		dist -= (m[v[l]] == 0);
		ans += r - l;
	}
	printf("%lli\n", ans);
	
	return 0;
}
