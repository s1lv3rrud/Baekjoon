#include <bits/stdc++.h>

using namespace std;

int n, m;
char ar[1001][1001];
// index 0: 벽을 부수지 않은 경우
// index 1: 벽을 부순 경우
int visited[1000][1000][2];
queue<tuple<int, int, int>> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isIn(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int BFS() {
    while (!q.empty()) {
        int x, y, wall;
        tie(x, y, wall) = q.front();
        if (x == n - 1 && y == m - 1) return visited[x][y][wall];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isIn(nx, ny)) continue;
            if (ar[nx][ny] == '0' && visited[nx][ny][wall] == -1) {
                visited[nx][ny][wall] = visited[x][y][wall] + 1;
                q.push(make_tuple(nx, ny, wall));
            }
            if (wall == 0 && ar[nx][ny] == '1' && visited[nx][ny][1] == -1) {
                visited[nx][ny][1] = visited[x][y][wall] + 1;
                q.push(make_tuple(nx, ny, 1));
            }
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(visited, -1, sizeof(int) * 1000 * 1000 * 2);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = 1;
    visited[0][0][1] = 1; // 예외 기본값

    cout << BFS();

    return 0;
}