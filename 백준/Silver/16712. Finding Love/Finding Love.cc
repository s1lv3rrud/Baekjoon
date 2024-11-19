#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int v;
  for (int i = 0; i < n - m + 1; i++) {
    cin >> v;
    sort(a.begin(), a.begin() + m);
    a.erase(a.begin() + v - 1);
  }

  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }

  return 0;
}
