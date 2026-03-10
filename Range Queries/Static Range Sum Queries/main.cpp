#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5;
 
long long pref[NMAX];
 
int main() {
	int n;
	scanf("%d",&n);
	int q;
	scanf("%d",&q);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d",&x);
		pref[i] = pref[i-1] + x;
	}
	while(q--) {
		int x, y;
		scanf("%d %d",&x,&y);
		printf("%lli\n",pref[y] - pref[x-1]);
	}
	return 0;
}
