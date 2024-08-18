/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int left = 0, right = n - 1, res = abs(v[left] + v[right]),
      res_left = v[left], res_right = v[right];
  while (left < right) {
    int cur = v[left] + v[right];
    if (abs(cur) < res) {
      res = abs(cur);
      res_left = v[left];
      res_right = v[right];
    }

    if (cur < 0) {
      left++;
    } else {
      right--;
    }
  }

  cout << res_left << " " << res_right;

  return 0;
}