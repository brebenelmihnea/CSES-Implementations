#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.tie(nullptr)->sync_with_stdio(false);

    int n, w;
    cin >> n >> w;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int gondolas = 0, l = 1, r = n;
    while (l <= r) {
        if (v[l] + v[r] <= w) {
            l++, r--;
        } else {
            r--;
        }
        gondolas++;
    }

    cout << gondolas << '\n';

    return 0;
}
