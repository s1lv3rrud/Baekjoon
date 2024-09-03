/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, i, j, k;
  cin >> n >> m;

  vector<int> v(n);
  while(m--){
    cin >> i >> j >> k;
    for(int l = i-1; l <= j-1; l++){
      v[l] = k;
    }
  }
  for(int l = 0; l < n; l++){
    cout << v[l] << " ";
  }



  return 0;
}