/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int l, p;
  cin >> l >> p;
  int n = l * p;

  for (int i = 0; i < 5; i++) {
    int a;
    cin >> a;
    cout << a - n << " ";
  }

  return 0;
}