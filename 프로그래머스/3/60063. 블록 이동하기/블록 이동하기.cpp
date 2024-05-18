#include <bits/stdc++.h>

using namespace std;

int n;
// 상 좌 하 우
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int visited[100][100][4];

bool isIn(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int solution(vector<vector<int>> board) {
    n = board.size();

    // x, y, cnt, dir
    queue<tuple<int, int, int, int>> q;

    q.push({ 0, 0, 0, 3 });
    visited[0][0][3] = true;

    q.push({ 0, 1, 0, 1 });
    visited[0][1][1] = true;

    while (!q.empty()) {
        int x1, y1, x2, y2, cnt, dir;
        tie(x1, y1, cnt, dir) = q.front();
        q.pop();

        x2 = x1 + dx[dir];
        y2 = y1 + dy[dir];

        if((x1 == n - 1 && y1 == n - 1) || (x2 == n - 1 && y2 == n - 1)) {
            return cnt;
		}

        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];

            if(!isIn(nx1, ny1) || !isIn(nx2, ny2) 
                || board[nx1][ny1] || board[nx2][ny2]) {
				continue;
			}

            // 이동
            if(!visited[nx1][ny1][dir]) {
				visited[nx1][ny1][dir] = true;
				q.push({ nx1, ny1, cnt + 1, dir });
			}
            int ndir = (dir + 2) % 4; // 반대 방향
            if (!visited[nx2][ny2][ndir]) {
                visited[nx2][ny2][ndir] = true;
                q.push({ nx2, ny2, cnt + 1, ndir });
            }

            // 회전
            if ((dir + 1) % 2 == i % 2) {
                if (!visited[nx1][ny1][i]) {
                    visited[nx1][ny1][i] = true;
                    q.push({ x1, y1, cnt + 1, i });
                }
                ndir = (dir + 2) % 4; // 반대 방향
                if (!visited[nx2][ny2][ndir]) {
                    visited[nx2][ny2][ndir] = true;
                    q.push({ x2, y2, cnt + 1, ndir });
                }
            }
        }
    }
}