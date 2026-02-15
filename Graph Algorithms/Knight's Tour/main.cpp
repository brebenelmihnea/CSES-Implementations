#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8;

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int board[MAXN + 5][MAXN + 5];


bool inside(int x, int y) {
    return (1 <= x && x <= MAXN && 1 <= y && y <= MAXN && board[x][y] == 0);
}

int get_degree(int x, int y) {
    int cnt = 0;
    for (int dir = 0; dir < 8; dir++) {
        int newx = x + dx[dir];
        int newy = y + dy[dir];
        if (inside(newx, newy)) {
            cnt++;
        }
    }
    return cnt;
}

bool solve(int x, int y, int nr) {
    board[x][y] = nr;
    if (nr == MAXN * MAXN) { return true; }
    vector<pair<int, int>> moves;
    for (int dir = 0; dir < 8; dir++) {
        int newx = x + dx[dir];
        int newy = y + dy[dir];
        if (inside(newx, newy)) {
            moves.push_back({get_degree(newx, newy), dir});
        }
    }
    sort(moves.begin(), moves.end());
    for (auto move : moves) {
        int dir = move.second, newx = x + dx[dir], newy = y + dy[dir];
        if (solve(newx, newy, nr + 1)) { return true; }
    }
    board[x][y] = 0;
    return false;

}

int main() {


    int x, y;
    cin >> y >> x;

    solve(x, y, 1);

    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
