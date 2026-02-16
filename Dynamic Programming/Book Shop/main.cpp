#include <bits/stdc++.h> 
 
using namespace std;
 
const int NMAX = 1003;
const int XMAX = 2e5;
int n, x;
int v[NMAX], s[NMAX], dp[XMAX];
 
int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> s[i];
    
    for(int i = 1; i <= n; i++) 
        for(int j = x; j >= v[i]; j--) 
            dp[j] = max(dp[j], dp[j - v[i]] + s[i]);
        
    cout << dp[x] ;
 
    return 0;
}
