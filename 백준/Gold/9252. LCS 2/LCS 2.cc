/*

 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s1, s2;
  cin >> s1 >> s2;

  int n = s1.size();
  int m = s2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // dp
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string ans = "";
  while (n > 0 && m > 0) {
    if (s1[n - 1] == s2[m - 1]) {
      ans = s1[n - 1] + ans;
      n--;
      m--;
    } else {
      if (dp[n][m] == dp[n - 1][m]) {
        n--;
      } else {
        m--;
      }
    }
  }

  cout << dp[s1.size()][s2.size()] << '\n';
  if (dp[s1.size()][s2.size()] != 0) cout << ans;

  return 0;
}