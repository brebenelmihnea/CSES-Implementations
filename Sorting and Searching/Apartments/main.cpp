#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d",&n, &m, &k);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    vector<int> b(m);
    for(int i = 0; i < m; i++)
        scanf("%d",&b[i]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int x = 0, y = 0;
    int GotApartment = 0;
    while(x < n && y < m) {
        if(a[x]-k <= b[y] && b[y] <= a[x]+k) {
            GotApartment++;
            x++;
            y++;
        } else if(b[y] > a[x]) {
            x++;
        } else {
            y++;
        }
    }
    printf("%d\n",GotApartment);

    return 0;
}
