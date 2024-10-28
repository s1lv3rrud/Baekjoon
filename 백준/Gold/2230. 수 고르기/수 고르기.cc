/*
2230 수 고르기
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ans = 2e9;
  int i = 0, j = 0;
  for (; i < n; i++) {
    while (j < n && a[j] - a[i] < m) {
      j++;
    }
    if (j == n) {
      break;
    }
    ans = min(ans, a[j] - a[i]);
  }

  cout << ans;

  return 0;
}
