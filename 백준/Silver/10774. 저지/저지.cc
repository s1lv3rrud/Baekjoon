/*
 */

#include <bits/stdc++.h>

using namespace std;
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int j, a;
  cin >> j >> a;
  vector<int> size(j + 1);
  for (int i = 1; i <= j; i++) {
    char c;
    cin >> c;
    if (c == 'S') {
      size[i] = 1;
    } else if (c == 'M') {
      size[i] = 2;
    } else if (c == 'L') {
      size[i] = 3;
    }
  }

  int ans = 0;
  for (int i = 0; i < a; i++) {
    char c;
    int reqSize, reqNum;
    cin >> c >> reqNum;
    if (c == 'S') {
      reqSize = 1;
    } else if (c == 'M') {
      reqSize = 2;
    } else if (c == 'L') {
      reqSize = 3;
    }
    if (size[reqNum] >= reqSize) {
      size[reqNum] = 0;
      ans++;
    }
  }

  cout << ans;

  return 0;
}
