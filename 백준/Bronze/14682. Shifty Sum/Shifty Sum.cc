/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, ans;
  cin >> n >> k;
  ans = n;
  while(k--){
    n *= 10;
    ans += n;
  }
  cout << ans << '\n';

  return 0;
}