#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n;
	long long k;
	cin >> n >> k;
 
	long long max_val = 0, sum = 0;
	vector<long long> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		max_val = max(max_val, v[i]);
		sum += v[i];
	}
 
	auto check = [&](const long long max_sum_limit) -> bool {
		long long current_sum = 0, subarrays_needed = 1;
		for (int i = 1; i <= n; i++) {
			if (v[i] > max_sum_limit) { return false; }
			if (current_sum + v[i] <= max_sum_limit) {
				current_sum += v[i];
			} else {
				subarrays_needed++;
				current_sum = v[i];
			}
		}
		return subarrays_needed <= k;
	};
 
	long long l = max_val, r = sum, last = r;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if(check(mid)) {
			last = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
 
	cout << last << '\n';
	
	return 0;
}
