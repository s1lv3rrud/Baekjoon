/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

   int n, m;
    cin >> n >> m;
    vector<int> v;
    v.push_back(0);
    for(int i = 0;i<n;i++){
      v.push_back(i+1);
    }

    for(int i = 0;i<m;i++){
      int l, r;
      cin >> l >> r;
      int tmp = v[l];
      v[l] = v[r];
      v[r] = tmp;
    }

    for(int i = 1;i<=n;i++){
      cout << v[i] << " ";
    }


  return 0;
}