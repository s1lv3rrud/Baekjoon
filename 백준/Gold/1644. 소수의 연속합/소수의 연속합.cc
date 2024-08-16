/*
에라토스테네스의 체
N의 제곱근까지만 반복하여 소수를 찾는 방법
N의 범위 : 400만
소수 판별 함수 : O(N^1/2)
400만 * 400만 = 16조 => 시간초과
O(N)으로 풀어야 함
 */

#include <bits/stdc++.h>
using namespace std;

bool isSosu(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int ans = 0;
  vector<int> curSum;
  for (int i = 2; i <= n; i++) {
    if (!isSosu(i)) continue;
    curSum.push_back(i);
    while (accumulate(curSum.begin(), curSum.end(), 0) > n) {
      curSum.erase(curSum.begin());
    }
    if (accumulate(curSum.begin(), curSum.end(), 0) == n) ans++;
  }

  cout << ans;

  return 0;
}