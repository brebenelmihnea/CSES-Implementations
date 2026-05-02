#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	string s, pattern;
	cin >> s >> pattern;
 
	s = pattern + '#' + s;
	vector<int> pi(s.size(), 0);
	for(int i = 1, j = 0; i < (int)s.size(); i++) {
		while(j > 0 && s[i] != s[j]) { j = pi[j - 1]; }
		if(s[i] == s[j]) { j++; }
		pi[i] = j;
	}
 
	int cnt = 0;
	for(auto i : pi) { 
		cnt += (i == pattern.size());
	}
	cout << cnt << '\n';
 
	return 0;
}
