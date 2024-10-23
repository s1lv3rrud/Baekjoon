#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int hh, mm;
  cin >> hh >> mm;

  int h, m, ans = 0;
  h = hh-9;
  m = mm-0;

  if(h < 0){
    h += 24;
  }

  ans = h*60 + m;
  cout << ans << endl;

  return 0;
}
