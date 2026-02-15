#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {

    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end(),cmp);

    int cnt = 1;
    pair<int,int> last = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i].first >= last.second) {
            cnt++;
            last = v[i];
        }
    }

    cout << cnt << '\n';
    
    return 0;
}
