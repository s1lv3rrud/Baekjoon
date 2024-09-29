/*
14722 우유 도시
딸기 -> 초코 -> 바나나 -> 딸기 -> 초코 -> 바나나 -> ...
0 : 딸기 1 : 초코 2 : 바나나
4
0 1 2 2
1 1 1 1
2 2 2 2
0 0 1 0
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int N;
int city[MAX][MAX];
int dp[MAX][MAX][3];

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> city[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[0][i][j] = 0;
      dp[i][0][j] = 0;
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int milk = 0; milk < 3; milk++) {
        if (city[i][j] == milk) {
          dp[i][j][milk] =
              max(dp[i - 1][j][(milk + 2) % 3], dp[i][j - 1][(milk + 2) % 3]);
          if (milk == 0 || dp[i][j][milk] != 0) {
            dp[i][j][milk]++;
          }
        } else {
          dp[i][j][milk] = max(dp[i - 1][j][milk], dp[i][j - 1][milk]);
        }
      }
    }
  }

  cout << max(dp[N][N][0], max(dp[N][N][1], dp[N][N][2]));

  return 0;
}