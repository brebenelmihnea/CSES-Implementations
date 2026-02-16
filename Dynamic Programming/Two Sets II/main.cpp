#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
 
    const int MOD = 1e9 + 7;
 
    int n;
    cin >> n;
 
    int total_sum = n * (n + 1) / 2;
    if (total_sum % 2) {
        cout << 0 << '\n';
        return 0;
    }
 
    vector<ll> dp(total_sum + 1, 0);
 
    dp[0] = 1;
 
    for (int i = 1; i < n; i++) {
        for (int j = total_sum / 2; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
 
    cout << dp[total_sum / 2]  << endl;
 
    return 0;
}
