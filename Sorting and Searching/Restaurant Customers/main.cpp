#include <bits/stdc++.h>

using namespace std;

int main() {
    
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,1});
        v.push_back({y,-1});
    }
    
    sort(v.begin(),v.end());
    
    int ans = 0, cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        cnt += v[i].second;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
