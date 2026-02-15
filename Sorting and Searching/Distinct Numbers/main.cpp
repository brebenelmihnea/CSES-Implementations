#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    set<int> s;
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        s.insert(value);
    }

    cout << s.size() << '\n';

    return 0;
}
