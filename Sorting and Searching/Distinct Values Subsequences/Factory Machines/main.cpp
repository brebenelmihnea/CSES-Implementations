#include <bits/stdc++.h>

using namespace std;

int main() {
	
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	long long t;
	cin >> n >> t;

	vector<long long> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	auto ok = [&](long long time) -> bool {
		long long cnt = 0;
		for(int i = 1; i <= n; i++) {
			cnt += time / v[i];
			if (cnt >= t) { return true; }
		}
		return false;
	};

	long long l = 0, r = 1e18, last = r;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if(ok(mid)) {
			last = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << last;

	return 0;
}
