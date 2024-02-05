#include <bits/stdc++.h>

using namespace std;

int n, m, maxWeight = 0;
int paper[500][500];
bool visited[500][500];

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
        weight++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(nx, ny) && !visited[nx][ny] && paper[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    if (weight > maxWeight) maxWeight = weight;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    int painting = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && paper[i][j] == 1) {
                painting++;
                visited[i][j] = true;
                q.push(make_pair(i, j));
                BFS();
            }
        }
    }

    cout << painting << "\n" << maxWeight;

    return 0;
}