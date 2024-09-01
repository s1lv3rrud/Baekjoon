/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, ans = 0;
  cin >> n >> k;

  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] != 'P') continue;  // 사람

    for (int j = i - k; j <= i + k; j++) {
      if (j < 0 || j >= n) continue;
      if (s[j] == 'H') {  // 햄버거
        s[j] = 'X';
        ans++;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}