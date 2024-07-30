#include <bits/stdc++.h>

using namespace std;
int n, m, k, r, c, s;
bool board[40][40];
vector<pair<int, int>> sticker;

void rotate() {
  vector<pair<int, int>> rotatedSticker;
  for (int i = 0; i < sticker.size(); i++) {
    int x = sticker[i].first;
    int y = sticker[i].second;
    rotatedSticker.push_back({y, r - 1 - x});
  }
  sticker = rotatedSticker;
  swap(r, c);
}

int count() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j]) cnt++;
    }
  }
  return cnt;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  while (k--) {
    cin >> r >> c;
    sticker.clear();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> s;
        if (s) {
          sticker.push_back({i, j});
        }
      }
    }

    bool completed = false;
    int rotateCnt = 0;
    while (rotateCnt < 4) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          bool tmpBoard[40][40];
          memset(tmpBoard, 0, sizeof(tmpBoard));

          for (int stick = 0; stick < sticker.size(); stick++) {
            int x = sticker[stick].first + i, y = sticker[stick].second + j;
            if (rotateCnt == 4) break;
            if (n - i < r || m - j < c) {
              break;
            } else if (board[x][y]) {
              break;
            } else {
              tmpBoard[x][y] = true;
            }
            if (stick == sticker.size() - 1) {
              completed = true;
            }
          }

          if (completed) {
            for (int a = 0; a < n; a++) {
              for (int b = 0; b < m; b++) {
                if (tmpBoard[a][b]) board[a][b] = tmpBoard[a][b];
              }
            }
            break;
          }
        }
        if (completed) break;
      }
      if (!completed) {
        rotate();
        rotateCnt++;
      } else {
        break;
      }
    }

    completed = false;
  }
  cout << count();

  return 0;
}
