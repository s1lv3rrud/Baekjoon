#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0;
int ar[1000][1000];
int visited[1000][1000][2]; // 0: group index, 1: area size
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int groupIndex = 0;

void bfs(int curx, int cury) {
	groupIndex++;
	queue<pair<int, int>> q;
	q.push({ curx, cury });
	
	queue<pair<int, int>> group;
	group.push({ curx, cury });
	
	visited[curx][cury][0] = groupIndex;

	int areaSize = 1;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny][0]) continue;
			if (ar[nx][ny] == 0) continue;
			areaSize++;
			visited[nx][ny][0] = groupIndex;
			q.push({ nx, ny });
			group.push({ nx, ny });
		}
	}

	while (!group.empty()) {
		int x = group.front().first;
		int y = group.front().second;
		group.pop();
		visited[x][y][1] = areaSize;
	}
}


int main(int argc, char** argv) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ar[i][j] == 1 && !visited[i][j][0]) {
				bfs(i, j);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ar[i][j] == 0) {
				int area = 1;
				map<int, int> group;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					group[visited[nx][ny][0]] = visited[nx][ny][1];
				}
				for (auto g : group) {
					area += g.second;
				}
				ans = max(ans, area);
			}
		}
	}
	cout << ans;

    return 0;
}