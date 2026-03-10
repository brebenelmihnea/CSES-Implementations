#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 2e5+1;
 
int n, q;
int v[NMAX], ans[NMAX];
vector<pair<int, int>> queries[NMAX];
map<int, int> m;
 
struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 1) {}
	void update(int x, int v) {
		x++;
		for (; x <= size; x += x & (-x)) {
			bit[x] += v;
		}
	}
	int query(int b) {
		b++;
		int result = 0;
		for (; b > 0; b -= b & (-b)) {
			result += bit[b];
		}
		return result;
	}
} bit(NMAX);
 
int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &v[i]);
    for(int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        queries[x].push_back({y, i});
    }
    for(int i = n; i >= 1; i--) {
        if(m.count(v[i])) 
            bit.update(m[v[i]], -1);
        m[v[i]] = i;
        bit.update(i, 1);
        for(auto query : queries[i]) ans[query.second] = bit.query(query.first);
    }
    for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}
