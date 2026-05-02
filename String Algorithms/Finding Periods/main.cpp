#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	string s;
	cin >> s;
	vector<int> z(s.size());
	for(int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
		z[i] = max(0, min(z[i-l], r-i+1));
		while(i+z[i] < (int)s.size() && s[z[i]] == s[i+z[i]]) {
			l = i;
			r = i + z[i];
			z[i]++;
		}
		if(z[i]+i == (int)s.size()) {
			cout << i << ' ';
		}
	}
	cout << (int)s.size();
 
	return 0;
}
