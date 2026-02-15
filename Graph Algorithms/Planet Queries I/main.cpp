#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 3e5;
const int LOGMAX = 30;

int n, m;
int up[NMAX][LOGMAX];

int jump(int x, int y) {
    for(int i = 0; i < LOGMAX; i++) {
        if((1<<i) & y)
            x = up[x][i];
    }
    return x;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d" ,&up[i][0]);
    }
    for(int j = 1; j < LOGMAX; j++) {
        for(int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    while(m--) {
        int x, k;
        scanf("%d %d", &x, &k);
        printf("%d\n", jump(x, k));
    }

    return 0;
}
