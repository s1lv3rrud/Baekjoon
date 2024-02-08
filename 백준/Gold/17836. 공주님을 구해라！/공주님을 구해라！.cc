#include <bits/stdc++.h>

using namespace std;

int n, m, t, result = -1;
int miro[100][100];
int knight[100][100][2];

queue<pair<int, int>> q;
pair<int, int> gram;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool IsInside(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void BFS() {
    while (!q.empty()) {/*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << " " << knight[i][j][0];
            }
            cout << "\n";
        }
        cout << "\n";*/
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (knight[x][y][0] == t) break;

        if (x == gram.first && y == gram.second) {
            knight[x][y][1] = true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx == n - 1 && ny == m - 1) {
                result = knight[x][y][0] + 1;
                return; 
            }

            if (IsInside(nx, ny)) {
                if (knight[x][y][1] == 0) {
                    if (knight[nx][ny][0] == 0 && miro[nx][ny] == 0) {
                        q.push(make_pair(nx, ny));
                        knight[nx][ny][0] = knight[x][y][0] + 1;
                    }
                }
                else {
                    if (knight[nx][ny][1] == 0) {
                        q.push(make_pair(nx, ny));
                        knight[nx][ny][0] = knight[x][y][0] + 1;
                        knight[nx][ny][1] = true;
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> miro[i][j];
            if (miro[i][j] == 2) {
                gram = make_pair(i, j);
                miro[i][j] = 0;
            }
        }
    }

    q.push(make_pair(0, 0));
    

    BFS();

    result == -1 ? cout << "Fail" : cout << result;

    return 0;
}