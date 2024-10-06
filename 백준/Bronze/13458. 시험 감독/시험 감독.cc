/*
13458 시험 감독
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int b, c;
  cin >> b >> c;

  long long ans = 0;
  for(auto num : a){
    num -= b;
    ans++;
    if(num > 0){
      ans += num / c;
      if(num % c != 0){
        ans++;
      }
    }
  }

  cout << ans;

  return 0;
}