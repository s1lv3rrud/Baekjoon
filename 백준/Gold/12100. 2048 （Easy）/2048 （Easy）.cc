#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
int board[20][20];

void move(int dir) {
  queue<int> q;
  // left, right, up, down
  switch (dir) {
    case 0:
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] != 0) {
            q.push(board[i][j]);
            board[i][j] = 0;
          }
        }
        int curIdx = 0;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (board[i][curIdx] == 0) {
            board[i][curIdx] = num;
          } else if (board[i][curIdx] == num) {
            board[i][curIdx] *= 2;
            curIdx++;
          } else {
            curIdx++;
            board[i][curIdx] = num;
          }
        }
      }
      break;
    case 1:
      for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
          if (board[i][j] != 0) {
            q.push(board[i][j]);
            board[i][j] = 0;
          }
        }
        int curIdx = n - 1;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (board[i][curIdx] == 0) {
            board[i][curIdx] = num;
          } else if (board[i][curIdx] == num) {
            board[i][curIdx] *= 2;
            curIdx--;
          } else {
            curIdx--;
            board[i][curIdx] = num;
          }
        }
      }
      break;
    case 2:
      for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
          if (board[i][j] != 0) {
            q.push(board[i][j]);
            board[i][j] = 0;
          }
        }
        int curIdx = 0;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (board[curIdx][j] == 0) {
            board[curIdx][j] = num;
          } else if (board[curIdx][j] == num) {
            board[curIdx][j] *= 2;
            curIdx++;
          } else {
            curIdx++;
            board[curIdx][j] = num;
          }
        }
      }
      break;
    case 3:
      for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
          if (board[i][j] != 0) {
            q.push(board[i][j]);
            board[i][j] = 0;
          }
        }
        int curIdx = n - 1;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (board[curIdx][j] == 0) {
            board[curIdx][j] = num;
          } else if (board[curIdx][j] == num) {
            board[curIdx][j] *= 2;
            curIdx--;
          } else {
            curIdx--;
            board[curIdx][j] = num;
          }
        }
      }
      break;
  }
}

void dfs(int depth) {
  if (depth == 5) return;

  int tmpBoard[20][20];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmpBoard[i][j] = board[i][j];
    }
  }

  for (int d = 0; d < 4; d++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        board[i][j] = tmpBoard[i][j];
      }
    }

    move(d);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, board[i][j]);
      }
    }
    dfs(depth + 1);
  }
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  dfs(0);

  cout << ans;

  return 0;
}