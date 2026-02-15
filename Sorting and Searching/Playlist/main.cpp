#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int,int> m;
    int lg = 0, ans = 0, last = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(!m.count(x)) {
            lg++;
            ans = max(ans, lg);
            m[x] = i;
        } else {
            last = max(last, m[x]);
            m[x] = i;
            lg = i-last;
            ans = max(ans, lg);
        }
    }
    
    cout << ans << '\n';

    return 0;
}
