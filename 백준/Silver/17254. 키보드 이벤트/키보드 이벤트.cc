/*

 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, char>> keys(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    keys[i] = {b, a, c};
  }

  sort(keys.begin(), keys.end());

  for(auto [a, b, c] : keys) {
    cout << c;
  }

  return 0;
}