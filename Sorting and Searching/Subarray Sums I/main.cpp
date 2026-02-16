#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n,x;
	scanf("%d %d",&n,&x);
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&v[i]);
	}
	int l = 1,r = 1;
	int s = v[1];
	int cnt = 0;
	while(r <= n) {
		if(s == x){
			cnt ++;
			s += v[++r];
			s -= v[l++];
		}else if(s < x) {
			s += v[++r];
		}else{
			s -= v[l++];
		}
	}
	printf("%d\n",cnt);
}
