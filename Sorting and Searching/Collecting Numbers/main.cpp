#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> f(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x-1] = i;
    }

    int cnt = 1;
    for(int i = 0; i < n-1; i++) {
        if(f[i] > f[i+1]) {
            cnt++;
        }
    }
    
    cout << cnt << '\n';

    return 0;
}
