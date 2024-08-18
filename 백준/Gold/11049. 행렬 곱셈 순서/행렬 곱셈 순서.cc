/*
여러 개의 행렬의 곱을 두 행렬의 곱으로 생각할 수 있다.
dp 배열의 n행 m열은 n번째 행렬부터 m번째 행렬까지의 곱의 최소 곱셈 연산
횟수이다. 행렬의 곱에서는 곱의 순서가 어떻든 결론적으로 첫 번째 행렬과 마지막
행렬을 곱하는 것이다. dp[i][i + j]의 점화식 : dp[j][k] + dp[k + 1][i + j] +
N(v[j].first) * M(v[k].second) * K(v[i + j].second)
 */

#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  for (int i = 1; i < n; i++) {         // 구간의 크기
    for (int j = 1; i + j <= n; j++) {  // 구간의 시작 지점
      // 구간의 끝 지점 : i + j
      dp[j][i + j] = INT_MAX;
      for (int k = j; k <= i + j; k++) {  // 구간의 중간 지점
        dp[j][i + j] =
            min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] +
                                  v[j].first * v[k].second * v[i + j].second);
      }
    }
  }
  cout << dp[1][n];

  return 0;
}