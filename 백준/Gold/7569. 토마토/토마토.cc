#include <bits/stdc++.h>

using namespace std;

int m, n, h;
int tomato[100][100][100];

queue<tuple<int, int, int>> q;

// 뒤 앞 좌 우 상 하
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0 ,0 };
int dz[6] = { 0 ,0, 0, 0, 1, -1 };

bool IsInside(int x, int y, int z) {
    return 0 <= x && 0 <= y && x < n && y < m && 0 <= z && z < h;
}

void BFS() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (IsInside(nx, ny, nz) && tomato[nz][nx][ny] == 0) {
                q.push(make_tuple(nx, ny, nz));
                tomato[nz][nx][ny] = tomato[z][x][y] + 1;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tomato[k][i][j];
                if (tomato[k][i][j] == 1) {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    BFS();

    int result = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tomato[k][i][j] == 0) {
                    cout << -1;
                    return 0;
                }
                tomato[k][i][j] >= result ? result = tomato[k][i][j] : result = result;
            }
        }
    }

    result--;
    cout << result;

    return 0;
}