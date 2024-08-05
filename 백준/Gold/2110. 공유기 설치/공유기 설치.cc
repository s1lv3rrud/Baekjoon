/*

 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  cin >> n >> c;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int start = 1, end = v[n-1] - v[0], ans = 0;

  while (start <= end) {
    int mid = (start + end) / 2;
    int cnt = 1, prev = v[0];
    for (int i = 1; i < n; i++) {
      if (v[i] - prev >= mid) {
        cnt++;
        prev = v[i];
      }
    }
    if (cnt >= c) {
      ans = max(ans, mid);
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << ans;  

  return 0;
}