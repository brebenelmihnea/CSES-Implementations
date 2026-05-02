#include <bits/stdc++.h>
 
using namespace std;
 
struct Point {
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}
 
	friend istream& operator>>(istream &in, Point &p) {
		int x, y;
		in >> p.x >> p.y;
		return in;
	}
};
 
long long collinear(Point p, Point p1, Point p2) {
	return 1LL * (p.y - p1.y) * (p2.x - p1.x) - 1LL * (p.x - p1.x) * (p2.y - p1.y);
}
 
int main()
{
	int t;
	cin >> t;
 
	while(t--) {
		Point p1, p2, p3;
		cin >> p1 >> p2 >> p3;
 
		if(collinear(p1, p2, p3) == 0) {
			cout << "TOUCH" << '\n';
		} else if(collinear(p1, p2, p3) < 0) {
			cout << "RIGHT" << '\n';
		} else {
			cout << "LEFT" << '\n';
		}
 
	}
 
    return 0;
}
