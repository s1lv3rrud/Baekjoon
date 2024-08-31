/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> v(n), complete(n - 1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> complete[i];
  }

  sort(v.begin(), v.end());
  sort(complete.begin(), complete.end());

  for (int i = 0; i < n - 1; i++) {
    if (v[i] != complete[i]) {
      cout << v[i];
      return 0;
    }
  }
  cout << v[n - 1];

  return 0;
}