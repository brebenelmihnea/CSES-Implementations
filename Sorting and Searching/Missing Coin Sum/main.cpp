#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    long long s = 1;
    for(int i = 0; i < n && v[i] <= s; i++) {
        s = s + v[i];
    }
    
    cout << s << '\n';

    return 0;
}
