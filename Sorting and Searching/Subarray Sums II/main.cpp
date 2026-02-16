#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	long long  Target; 
	scanf("%d %lli", &n, &Target);
	map<long long,int> m;
	m[0]++;
	long long ans = 0;
	long long S = 0;
	for(int i = 1; i <= n; i++) {
		long long x;
		scanf("%lli",&x);
		S += x;
		if(m.count(S-Target)) ans += m[S-Target];
		m[S]++;
	}
	printf("%lli\n", ans);
	return 0;
}
