#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int NMAX = 3e5;

int n, steps;
int t[NMAX], PathLenght[NMAX];
bool seen[NMAX];
queue<int> path;

void bfs(int planet) {
    path.push(planet);
    if(seen[planet]) {
        steps += PathLenght[planet];
        return ;
    }
    seen[planet] = 1;
    steps++;
    bfs(t[planet]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    for(int planet = 1; planet <= n; planet++) {
        if(!seen[planet]) {
            steps = 0;
            bfs(planet);
            int dec = 1;
            while(!path.empty()) {
                if(path.front() == path.back()) {
                    dec = 0;
                }
                PathLenght[path.front()] = steps;
                steps -= dec;
                path.pop();
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", PathLenght[i]);
    }
    puts("");

    return 0;
}
