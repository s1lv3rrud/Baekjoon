/*

 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string n1, n2;
  while (true) {
    cin >> n1 >> n2;
    if (n1 == "#" && n2 == "#") break;
    int n;
    cin >> n;
      int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
      char c1, c2;
      cin >> c1 >> c2;
      if (c1 == c2) {
        s1++;
      } else {
        s2++;
      }
    }

    cout << n1 << " " << s1 << " " << n2 << " " << s2 << "\n";
  }

  return 0;
}