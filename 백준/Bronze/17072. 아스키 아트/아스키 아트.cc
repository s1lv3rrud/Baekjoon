#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int r, g, b;
      cin >> r >> g >> b;
      int ascii = 2126 * r + 7152 * g + 722 * b;
      if (ascii < 510000)
        cout << '#';
      else if (ascii < 1020000)
        cout << 'o';
      else if (ascii < 1530000)
        cout << '+';
      else if (ascii < 2040000)
        cout << '-';
      else
        cout << '.';
    }
    cout << '\n';
  }

  return 0;
}
