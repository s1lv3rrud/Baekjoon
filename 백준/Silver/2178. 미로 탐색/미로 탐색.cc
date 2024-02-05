#include <bits/stdc++.h>

using namespace std;

int n, m;
int miro[100][100];
string input[100];

queue<pair<int, int>> q;

// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool IsInside(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void BFS() {
    int weight = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(nx, ny) && miro[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                miro[nx][ny] = miro[x][y] + 1;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
        for (int j = 0; j < m; j++) {
            miro[i][j] = input[i][j] - '0';
        }
    }

    q.push(make_pair(0, 0));

    BFS();

    cout << miro[n - 1][m - 1];

    return 0;
}