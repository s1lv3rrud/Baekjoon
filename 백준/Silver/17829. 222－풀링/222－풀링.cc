/*

 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  while (n != 1) {
    vector<vector<int>> temp(n / 2, vector<int>(n / 2));

    for(int i = 0;i<n/2;i++){
      for(int j = 0;j<n/2;j++){
        int x = 2 * i, y = 2 * j;
        vector<int> t;
        t.push_back(v[x][y]);
        t.push_back(v[x + 1][y]);
        t.push_back(v[x][y + 1]);
        t.push_back(v[x + 1][y + 1]);
        sort(t.begin(), t.end(), greater<int>());
        temp[i][j] = t[1];
      }
    }

    v = temp;

    n /= 2;
  }

  cout << v[0][0];

  return 0;
}