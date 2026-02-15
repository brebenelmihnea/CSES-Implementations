#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int mid_val = v[n / 2 + n % 2];
    long long cost = 0;
    for (int i = 1; i <= n; i++) {
        cost += abs(v[i] - mid_val);
    }

    cout << cost << '\n';

    return 0;
}
