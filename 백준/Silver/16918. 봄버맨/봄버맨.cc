/*
r행 c열
폭탄은 3초 후 폭발 -> 파괴되어 빈 칸
인접한 네 칸도 함께 파괴
인접한 폭탄은 폭발 없이 파괴
봄버맨: 폭탄에 면역력, 자유롭게 이동 가능
1. 일부 칸에 폭탄 설치
2. 1초동안 아무것도 하지 않음
3. 폭탄이 설치되어 있지 않은 모든 칸에 폭탄 설치
4. 1초가 지난 후 3초 전에 설치된 폭탄 모두 폭발
5. 3과 4를 반복
 */

#include <bits/stdc++.h>
using namespace std;

int r, c, n, curN = 0;
char board[200][200];
int bomb[200][200];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void print() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << board[i][j];
    }
    cout << '\t';
    for (int j = 0; j < c; j++) {
      cout << bomb[i][j];
    }
    cout << '\n';
  }
  cout << '\n';
}

void duringSec() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == 'O') {
        bomb[i][j]++;
      }
    }
  }
}

void installBomb() {
  //cout << "installBomb\n";
  memset(board, 'O', sizeof(board));
}

void executeBomb() {
  //cout << "executeBomb\n";
  bool isBomb[200][200];
  memset(isBomb, 0, sizeof(isBomb));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (bomb[i][j] == 3) {
        isBomb[i][j] = true;
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
            continue;
          }
          isBomb[nx][ny] = true;
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (isBomb[i][j]) {
        board[i][j] = '.';
        bomb[i][j] = 0;
      }
    }
  }
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> n;
  memset(bomb, 0, sizeof(bomb));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'O') {
        bomb[i][j] += 1;
      }
    }
  }
  curN++;

  while (curN < n) {
    //cout << "duringSec\n";
    duringSec();
    //print();
    if (curN % 2 != 0) {
      installBomb();
    } else {
      executeBomb();
    }

    curN++;
    //print();
  }

  // print();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }

  return 0;
}