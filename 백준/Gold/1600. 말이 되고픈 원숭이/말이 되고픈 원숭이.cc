// 말: 체스판에서 말의 움직임
// 원숭이: 총 k번만 말처럼 움직임, 이외에는 인접한 칸으로만 움직임(상하좌우)
// 원숭이가 왼쪽위->오른쪽아래로 이동하는 최소한의 이동 횟수
#include <bits/stdc++.h>
using namespace std;

int k, w, h, ans = INT_MAX;
bool board[200][200];
bool visited[200][200][31];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int hx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(){
	queue<tuple<int, int, int, int>> q;
	q.push({0, 0, 0, 0});
	visited[0][0][0] = true;
	while(!q.empty()){
		int x, y, horse, cnt;
		tie(x, y, horse, cnt) = q.front();
		//cout << x << " " << y << " " << horse << " " << cnt << "\n";
		q.pop();
		for(int i = 0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if(visited[nx][ny][horse]) continue;
			if(board[nx][ny]) continue;
			if(nx == h-1 && ny == w-1) {
				ans = min(ans, cnt+1);
			}else{
				q.push({nx, ny, horse, cnt+1});
			}
			visited[nx][ny][horse] = true;
		}
		if(horse < k){
			for(int i = 0;i<8;i++){
				int nx = x + hx[i];
				int ny = y + hy[i];
				if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if(visited[nx][ny][horse+1]) continue;
				if(board[nx][ny]) continue;
				if(nx == h-1 && ny == w-1) {
					ans = min(ans, cnt+1);
				}else{
					q.push({nx, ny, horse+1, cnt+1});
					//cout << nx << " " << ny << " " << horse << " " << cnt << "\n";
				}
				visited[nx][ny][horse+1] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}

	if(h == 1 && w == 1) {
		cout << 0;
		return 0;
	}

	bfs();

	if(ans == INT_MAX) cout << -1;
	else cout << ans;

	return 0;
}