#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[11][11];
queue<tuple<int, int, int, int, int>> q;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool visited[11][11][11][11];

void move(int& nx, int& ny, int& distance, int& dir) {
	while (board[nx + dx[dir]][ny + dy[dir]] != '#' && board[nx][ny] != 'O') {
		nx += dx[dir];
		ny += dy[dir];
		distance++;
	}
}

void BFS() {
	while (!q.empty()) {
		int rx, ry, bx, by, count;
		tie(rx, ry, bx, by, count) = q.front();
		q.pop();

		if (count >= 10) {
			cout << -1 << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by, ncount = count + 1;
			int r_distance = 0, b_distance = 0;

			move(nrx, nry, r_distance, i);
			move(nbx, nby, b_distance, i);

			if (board[nbx][nby] == 'O') continue;
			if (board[nrx][nry] == 'O') {
				cout << ncount << '\n';
				return;
			}

			if (nrx == nbx && nry == nby) {
				if (r_distance > b_distance) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}

			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx, nry, nbx, nby, ncount });
			}
		}
	}
	cout << -1 << '\n';
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	pair<int, int> red, blue;

    cin >> n >> m;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') red = { i, j };
			else if (board[i][j] == 'B') blue = { i, j };
		}
	}
	q.push({ red.first, red.second, blue.first, blue.second, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	BFS();

    return 0;
}