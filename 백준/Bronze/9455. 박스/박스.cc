/*

 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, m, n;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    int v[100][100];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
      }
    }
    int res = 0;
    for (int i = m - 2; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        if (v[i][j] == 1 && v[i + 1][j] == 0) {
          int x = i;
          while (x < m - 1 && v[x][j] == 1 && v[x + 1][j] == 0) {
            v[x + 1][j] = 1;
            v[x][j] = 0;
            x++;
            res++;
          }
        }
      }
    }
    cout << res << "\n";
  }

  return 0;
}
