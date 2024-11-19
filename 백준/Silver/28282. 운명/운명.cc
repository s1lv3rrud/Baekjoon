#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x; // x * x 연산에서 int * int 연산 발생 -> overflow
  int k;
  cin >> x >> k;

  vector<long long> l(k + 1, 0), r(k + 1, 0);

  for (int i = 0; i < x; i++) {
    int a;
    cin >> a;
    l[a]++;
  }

  for (int i = 0; i < x; i++) {
    int a;
    cin >> a;
    r[a]++;
  }

  long long ans = x * x;
  for (int i = 1; i <= k; i++) {
    ans -= l[i] * r[i];
  }

  cout << ans;

  return 0;
}
