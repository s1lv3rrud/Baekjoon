/*
20057 마법사 상어와 토네이도
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  int x = n / 2;
  int y = n / 2;
  int d = 0;
  int cnt = 1;
  int ans = 0;

  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};

  int xdx[4][9] = {{0, -1, 1, -2, 2, -1, 1, -1, 1},
                   {2, 1, 1, 0, 0, 0, 0, -1, -1},
                   {0, -1, 1, -2, 2, -1, 1, -1, 1},
                   {-2, -1, -1, 0, 0, 0, 0, 1, 1}};
  int xdy[4][9] = {{-2, -1, -1, 0, 0, 0, 0, 1, 1},
                   {0, -1, 1, -2, 2, -1, 1, -1, 1},
                   {2, 1, 1, 0, 0, 0, 0, -1, -1},
                   {0, -1, 1, -2, 2, -1, 1, -1, 1}};

  double ratio[9] = {0.05, 0.1, 0.1, 0.02, 0.02, 0.07, 0.07, 0.01, 0.01};

  while (x >= 0 || y >= 0) {
    for (int k = 0; k < 2; k++) {
      for (int c = 0; c < cnt; c++) {
        if (x == 0 && y == 0) {
          ans += v[x][y];
          cout << ans;
          return 0;
        }
        x += dx[d];
        y += dy[d];
        int sand = v[x][y];
        int asand = sand;
        v[x][y] = 0;
        int ax = x + dx[d];
        int ay = y + dy[d];
        //cout << "\n";
        for (int i = 0; i < 9; i++) {
          int nx = x + xdx[d][i];
          int ny = y + xdy[d][i];
          int nsand = sand * ratio[i];
          //cout << nx << " " << ny << " " << nsand << " " << d << "\n";
          asand -= nsand;
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            ans += nsand;
          } else {
            v[nx][ny] += nsand;
          }
        }

        if (ax < 0 || ax >= n || ay < 0 || ay >= n) {
          ans += asand;
        } else {
          v[ax][ay] += asand;
        }
        // cout << x << " " << y << "\n";
        // for (int i = 0; i < n; i++) {
        //   for (int j = 0; j < n; j++) {
        //     cout << v[i][j] << " ";
        //   }
        //   cout << "\n";
        // }
      }
      d = (d + 1) % 4;
    }
    cnt++;
  }

  return 0;
}