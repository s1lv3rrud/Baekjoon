/*

 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> mabangjin(n);
  for (int i = 0; i < n; i++) {
    cin >> mabangjin[i];
  }

  for(int i = 0; i< n;i++){
    string s;
    for(int j = 0; j < n; j++){
      s += mabangjin[j][i];
    }
    if(s != mabangjin[i]){
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}