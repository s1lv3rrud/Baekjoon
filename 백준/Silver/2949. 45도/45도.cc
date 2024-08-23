/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c, k;
  cin >> r >> c;
  vector<string> v(r);
  for (int i = 0; i < r; i++) {
    cin >> v[i];
  }
  cin >> k;

  // 45 90 135 180 225(180+45) 270(180+90) 315(180+135)
  k %= 360;
  if (k >= 180) {
    for (int i = 0; i < r / 2; i++) {
      reverse(v[i].begin(), v[i].end());
      reverse(v[r - i - 1].begin(), v[r - i - 1].end());
      string tmp = v[i];
      v[i] = v[r - i - 1];
      v[r - i - 1] = tmp;
    }
    if (r % 2 == 1) reverse(v[r / 2].begin(), v[r / 2].end());
    k -= 180;
  }
  if (k >= 90) {
    vector<string> tmp(c, string(r, ' '));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        tmp[j][r - i - 1] = v[i][j];
      }
    }
    v = tmp;
    k -= 90;
    swap(r, c);
  }
  if (k == 45) {
    vector<string> tmp(r + c - 1, string((r > c ? r : c) * 2 - 1, ' '));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        tmp[i + j][r - i - 1 + j] = v[i][j];
      }
    }
    v = tmp;
    r = r + c - 1;
  }

  for (int i = 0; i < r; i++) {
    int idx = v[i].size() - 1;
    while (v[i][idx] == ' ') idx--;
    cout << v[i].substr(0, idx + 1) << '\n';
  }

  return 0;
}