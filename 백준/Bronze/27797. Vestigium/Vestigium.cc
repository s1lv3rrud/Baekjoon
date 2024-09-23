/*

 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cin >> v[j][k];
      }
    }
    int dig_sum = 0, row_dup = 0, col_dup = 0;
    // 1. 대각선 합
    for (int j = 0; j < n; j++) {
      dig_sum += v[j][j];
    }
    // 2. 중복 요소 행 개수
    for (int j = 0; j < n; j++) {
      vector<int> check(n + 1, 0);
      for (int k = 0; k < n; k++) {
        check[v[j][k]]++;
      }
      for (int k = 1; k <= n; k++) {
        if (check[k] > 1) {
          row_dup++;
          break;
        }
      }
    }
    // 3. 중복 요소 열 개수
    for (int j = 0; j < n; j++) {
      vector<int> check(n + 1, 0);
      for (int k = 0; k < n; k++) {
        check[v[k][j]]++;
      }
      for (int k = 1; k <= n; k++) {
        if (check[k] > 1) {
          col_dup++;
          break;
        }
      }
    }
    cout << "Case #" << i + 1 << ": " << dig_sum << " " << row_dup << " "
         << col_dup << "\n";
  }

  return 0;
}