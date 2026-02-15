#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> t(m+1);
    for(int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    for(int i = 1; i <= m; i++)	 {
        auto poz = s.upper_bound(t[i]);
        if(poz == s.begin()) {
            cout << "-1\n";
        } else {
            cout << *(--poz) << '\n';
            s.erase(poz);
        }

    }
    return 0;
}
