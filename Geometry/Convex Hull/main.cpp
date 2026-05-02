#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int, int>> convexHull(vector<pair<int, int>> points) {
    vector<pair<int, int>> hull;
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    
    auto check = [](const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) -> bool {
        return 1LL * (c.second - a.second) * (b.first - a.first) - 1LL * (b.second - a.second) * (c.first - a.first) > 0;
    };
 
    for(int i = 0; i < points.size(); i++) {
        while(hull.size() > 1 && check(hull[hull.size() - 2], hull.back(), points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
 
    int lower_hull_size = hull.size();
    for(int i = points.size() - 2; i >= 0; i--) {
        while(hull.size() > lower_hull_size && check(hull[hull.size() - 2], hull.back(), points[i])) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
 
    hull.pop_back();
    return hull;    
}
 
int main() {
 
    int n;
    cin >> n;
 
    vector<pair<int, int>> points(n);
    for(pair<int, int> &p : points) {
        cin >> p.first >> p.second;
    }
 
    vector<pair<int, int>> convex_hull_points = convexHull(points);
 
    cout << convex_hull_points.size() << '\n';
    for(pair<int, int> &p : convex_hull_points) {
        cout << p.first << ' ' << p.second << '\n';
    } 
 
    return 0;
}
