/*
1300 : K번째 수
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {

  cin >> n >> k;

  int left = 1, right = k, mid;
  int result = 0;

  while (left <= right) {
    mid = (left + right) / 2;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += min(mid / i, n);
    }

    if (cnt < k) {
      left = mid + 1;
    } else {
      result = mid;
      right = mid - 1;
    }
  }

  cout << result << '\n';


  return 0;
}