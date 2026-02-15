#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long pref = 0, hmin = 0, ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref += x;
        ans = max(ans, pref - hmin);
        hmin = min(hmin, pref);
    }
    
    cout << ans << '\n';

    return 0;
}

