/*
16946 벽 부수고 이동하기 4
 */

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> v(1000, vector<int>(1000));
vector<vector<bool>> visited(1000, vector<bool>(1000));
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y){
  queue<pair<int, int>> q;
  vector<pair<int, int>> wall;
  q.push({x, y});
  visited[x][y] = true;
  int cnt = 1;

  while(!q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(visited[nx][ny]) continue;

      visited[nx][ny] = true;

      if(v[nx][ny] == 0){
        q.push({nx, ny});
        cnt++;
      }else{
        wall.push_back({nx, ny});
      }
    }
  }

  for(auto w : wall){
    v[w.first][w.second] += cnt;
    visited[w.first][w.second] = false;
  }
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      v[i][j] = s[j] - '0';
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(v[i][j] == 0 && !visited[i][j]){
        bfs(i, j);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << v[i][j] % 10;
    }
    cout << '\n';
  }

  return 0;
}