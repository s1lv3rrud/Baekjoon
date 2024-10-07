/*
14499 주사위 굴리기
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k;
vector<vector<int>> v(20, vector<int>(20));
vector<int> cmd;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> x >> y >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    cmd.push_back(a);
  }

  vector<int> dice(6);

  for(auto c : cmd){
    int nx = x + dx[c - 1];
    int ny = y + dy[c - 1];

    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

    if(c == 1){
      int temp = dice[0];
      dice[0] = dice[3];
      dice[3] = dice[5];
      dice[5] = dice[2];
      dice[2] = temp;
    } else if(c == 2){
      int temp = dice[0];
      dice[0] = dice[2];
      dice[2] = dice[5];
      dice[5] = dice[3];
      dice[3] = temp;
    } else if(c == 3){
      int temp = dice[0];
      dice[0] = dice[4];
      dice[4] = dice[5];
      dice[5] = dice[1];
      dice[1] = temp;
    } else if(c == 4){
      int temp = dice[0];
      dice[0] = dice[1];
      dice[1] = dice[5];
      dice[5] = dice[4];
      dice[4] = temp;
    }

    if(v[nx][ny] == 0){
      v[nx][ny] = dice[5];
    } else {
      dice[5] = v[nx][ny];
      v[nx][ny] = 0;
    }

    cout << dice[0] << "\n";

    x = nx;
    y = ny;
  }





  
  return 0;
}