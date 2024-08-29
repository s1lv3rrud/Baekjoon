/*

 */

#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 0;
int ar[26][26];

void backtracking(int x, int y) {
  if (x == n && y == m + 1) {
    ans++;
    return;
  }
  if (y == m + 1) {
    y = 1;
    x++;
  }

  ar[x][y] = 1;
  if (!(ar[x - 1][y - 1] && ar[x - 1][y] && ar[x][y - 1])) {
    backtracking(x, y + 1);
  }
  ar[x][y] = 0;
  backtracking(x, y + 1);
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  backtracking(1, 1);

  cout << ans;

  return 0;
}