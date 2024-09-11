#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p1, p2, p3, x1, x2, x3;
  cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;

  int ans = -1;
  for (int i = 1; i < p1 * p2 * p3; i++) {
    if (i % p1 == x1 && i % p2 == x2 && i % p3 == x3) {
      ans = i;
      break;
    }
  }
  cout << ans;

  return 0;
}