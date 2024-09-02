/*
합이 100이 되는 7개의 수를 찾아라
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v(9);
  for (int i = 0; i < 9; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  do {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
      sum += v[i];
    }
    if (sum == 100) {
      for (int i = 0; i < 7; i++) {
        cout << v[i] << '\n';
      }
      break;
    }
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}