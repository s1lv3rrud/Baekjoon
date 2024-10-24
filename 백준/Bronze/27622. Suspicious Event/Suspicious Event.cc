#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int ans = 0;

  vector<int> v;
  while(n--){
    int a;
    cin >> a;
    if(a > 0){
      v.push_back(a);
    } else {
      if(find(v.begin(), v.end(), -a) == v.end()){
        ans++;
      }
    }
  }

  cout << ans;

  return 0;
}
