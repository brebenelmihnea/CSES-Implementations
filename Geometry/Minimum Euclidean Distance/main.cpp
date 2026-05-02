#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
 
	int n;
	cin >> n;
 
	vector<pair<ll, ll>> points(n);
	for (auto &p : points) {
		cin >> p.first >> p.second;
	}
 
	sort(points.begin(), points.end());
 
	auto get_dist = [](const pair<ll, ll> &a, const pair<ll, ll> b) -> ll {
		return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
	};
 
	ll min_dist = LLONG_MAX;
	set<pair<ll, ll>> s = {{points[0].second, points[0].first}};
 
	for (int i = 1, j = 0; i < n; i++) {
 
		ll d = ceil(sqrt(min_dist));
		while (j < i && points[j].first < points[i].first - d) {
			s.erase({points[j].second, points[j].first});
			j++;
		}
 
		auto l = s.lower_bound({points[i].second - d, 0});
		auto r = s.upper_bound({points[i].second + d, 0});
 
		for (auto it = l; it != r; it++) {
			min_dist = min(min_dist, get_dist(points[i], {it->second, it->first}));
		}
 
		s.insert({points[i].second, points[i].first});
	}
 
	cout << min_dist;
 
	return 0;
}
