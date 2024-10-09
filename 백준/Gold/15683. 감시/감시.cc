/*
15683번 감시
0 : 빈 칸
1 : 1방향
2 : 마주보는 2방향
3 : 직각 2방향
4 : 3방향
5 : 4방향
6 : 벽
CCTV는 벽 통과 불가능
사각지대의 최소 크기
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<vector<int>> v(8, vector<int>(8));
vector<pair<int, int>> cctv;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void check(int x, int y, int dir) {
  int nx = x + dx[dir];
  int ny = y + dy[dir];

  while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
    if (v[nx][ny] == 6) break;
    if (v[nx][ny] == 0) v[nx][ny] = -1;
    nx += dx[dir];
    ny += dy[dir];
  }
}

void dfs(int idx) {
  if (idx == cctv.size()) { // 마지막 cctv까지 다 확인했을 때
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == 0) cnt++;
      }
    }
    ans = min(ans, cnt);
    return;
  }

  int x = cctv[idx].first;
  int y = cctv[idx].second;
  int type = v[x][y];

  if (type == 1) {
    for (int i = 0; i < 4; i++) {
      vector<vector<int>> temp = v;
      check(x, y, i);
      dfs(idx + 1);
      v = temp; // v를 원래대로 돌려놓기
    }
  } else if (type == 2) {
    for (int i = 0; i < 2; i++) {
      vector<vector<int>> temp = v;
      check(x, y, i);
      check(x, y, i + 2);
      dfs(idx + 1);
      v = temp;
    }
  } else if (type == 3) {
    for (int i = 0; i < 4; i++) {
      vector<vector<int>> temp = v;
      check(x, y, i);
      check(x, y, (i + 1) % 4);
      dfs(idx + 1);
      v = temp;
    }
  } else if (type == 4) {
    for (int i = 0; i < 4; i++) {
      vector<vector<int>> temp = v;
      check(x, y, i);
      check(x, y, (i + 1) % 4);
      check(x, y, (i + 2) % 4);
      dfs(idx + 1);
      v = temp;
    }
  } else if (type == 5) {
    vector<vector<int>> temp = v;
    check(x, y, 0);
    check(x, y, 1);
    check(x, y, 2);
    check(x, y, 3);
    dfs(idx + 1);
    v = temp;
  }
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  ans = n * m;


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] >= 1 && v[i][j] <= 5) {
        cctv.push_back({i, j});
      }
    }
  }

  dfs(0);
  cout << ans;

  return 0;
}