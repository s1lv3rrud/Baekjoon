/*
0
1: 0.5 + 0.5(2)
3: 1.5 + 0.5(4)
7: 3.5 + 0.5(8)
15: 7.5 + 0.5(16)
31: 15.5 + 0.5(32)
63: 31.5 + 0.5(64)
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    int ans = 1;
    for (int i = 0; i < k; i++) {
      ans *= 2;
    }
    cout << ans - 1 << "\n";
  }

  return 0;
}