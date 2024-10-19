#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, max_len = 0;
  cin >> n;

  long long a;

  vector<vector<long long>> v(n);
  for (int i = 0; i < n; i++) {
    while (true) {
      cin >> a;
      if (a == -1) break;
      v[i].push_back(a);
    }
    if (v[i].size() > max_len) {
      max_len = v[i].size();
    }
  }

  for (k = 0; k < max_len; k++) {
    bool flag = true;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].size() <= i) continue;
      for (int j = 0; j < i; j++) {
        if (v[j].size() <= j) continue;
        if (v[i][k] == v[j][k]) {
          flag = false;
          break;
        }
      }
      if (!flag) {
        break;
      }
    }
    if (flag) {
      break;
    }
  }

  if (k == max_len) {
    cout << max_len;
    return 0;
  }
  cout << k + 1;

  return 0;
}
