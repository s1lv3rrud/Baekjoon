#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  map<int, string> name;
  for (int i = 0; i < n; i++) {
    string s;
    int a;
    cin >> s >> a;
    if (name.find(a) != name.end()) {
      continue;
    }
    name[a] = s;
  }

  for (int i = 0; i < m; i++) {
    int fight;
    cin >> fight;
    auto it = name.lower_bound(fight);
    cout << (*it).second << "\n";
  }

  return 0;
}