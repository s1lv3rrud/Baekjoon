/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  string s;
  map<char, int> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (m.find(s[0]) == m.end()) {
      m.insert({s[0], 1});
    } else {
      m[s[0]]++;
    }
  }

  bool flag = false;
  for (auto a : m) {
    if (a.second >= 5) {
      cout << a.first;
      flag = true;
    }
  }
  if (!flag) cout << "PREDAJA";

  return 0;
}