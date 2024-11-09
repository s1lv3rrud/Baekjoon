#include <bits/stdc++.h>

using namespace std;

int solve(long long x) {
  if (x == 0)
    return 0;
  else if (x == 1)
    return 1;
  else if (x % 2 == 0)
    return solve(x / 2);
  else
    return 1 - solve(x / 2);
}

int main() {
  long long k;
  cin >> k;

  cout << solve(k - 1);

  return 0;
}