#include <bits/stdc++.h> 
 
using namespace std;
 
struct range {
    int l, r, idx;
    bool operator< (const range &other) {
        if(l == other.l) return r > other.r;
        return l < other.l;
    }
};
 
int n;
vector<range> ranges;
 
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        ranges.push_back({x, y, i});
    }    
    sort(ranges.begin(), ranges.end());
    vector<bool> contains(n), contained(n);
    int maxEnd = 0, minEnd = INT_MAX;
    for(auto range : ranges) {
        if(range.r <= maxEnd) contained[range.idx] = 1;
        maxEnd = max(maxEnd, range.r);
    }
    for(int i = ranges.size()-1; i >= 0; i--) {
        if(ranges[i].r >= minEnd) contains[ranges[i].idx] = 1;
        minEnd = min(minEnd, ranges[i].r);
    }
    for(int i = 0; i < n; i++) cout << contains[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << contained[i] << ' ' ;
 
    return 0;
}
