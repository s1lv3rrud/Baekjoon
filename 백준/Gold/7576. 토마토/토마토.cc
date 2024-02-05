#include <bits/stdc++.h>

using namespace std;

int m, n;
int tomato[1000][1000];

queue<pair<int, int>> q;

// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool IsInside(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(nx, ny) && tomato[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                tomato[nx][ny] = tomato[x][y] + 1;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    BFS();

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
            tomato[i][j] >= result ? result = tomato[i][j] : result = result;
        }
    }

    result--;
    cout << result;

    return 0;
}