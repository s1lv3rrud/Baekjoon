#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  int diff = INT_MAX;

  for (int i = 0; i < b.size() - a.size() + 1; i++) {
    int temp = 0;
    for (int j = 0; j < a.size(); j++) {
      if (b[j + i] != a[j]) {
        temp++;
      }
    }
    diff = min(diff, temp);
  }

  cout << diff << endl;

  return 0;
}
