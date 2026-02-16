#include <bits/stdc++.h> 
 
using namespace std;
 
const int NMAX = 20;
 
int n, x;
int weight[NMAX];
pair<int, int> dp[1<<NMAX];
 
int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> weight[i];
    dp[0] = {1, 0};
    for(int i = 1; i < (1<<n); i++)  {
        dp[i] = {n+1, 0};
        for(int j = 0; (1<<j) <= i; j++) 
            if((1<<j) & i) {
                auto without = dp[i^(1<<j)];
                if(without.second + weight[j] <= x)
                    without.second += weight[j];
                else {
                    without.first++;
                    without.second = weight[j];
                }
                dp[i] = min(dp[i], without);
            }
    }
    
    cout << dp[(1<<n) - 1].first;
 
    return 0;
}
