#include <bits/stdc++.h>

using namespace std;

int h, w, meltHour = 0, prevOneHour = 0;
int board[100][100];
int visited[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool bfs() {
	meltHour++;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (visited[nx][ny]) continue;
			if (board[nx][ny] == 0) {
				q.push({ nx, ny });
			}
			else {
				board[nx][ny] = 0;
				cnt++;
			}
			visited[nx][ny] = 1;
		}
	}
	
	if (cnt == 0) {
		cout << meltHour - 1 << '\n' << prevOneHour;
		return true;
	}
	else {
		prevOneHour = cnt;
		return false;
	}

}

int main(int argc, char** argv) {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		if (bfs()) break;
		memset(visited, 0, sizeof(visited));
	}

    return 0;
}