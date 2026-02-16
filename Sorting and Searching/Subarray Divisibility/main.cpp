#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	scanf("%d",&n);
	map<long long,int> m;
	m[0]++;
	long long ans = 0;
	long long s = 0;
	for(int i = 1; i <= n; i++) {
		long long x;
		scanf("%lli",&x);
		x %= n;
		s += x;
		s = ( s % n + n )% n;
		ans += m[s];
		m[s]++;
	}
	printf("%lli\n",ans);
	return 0;
}
