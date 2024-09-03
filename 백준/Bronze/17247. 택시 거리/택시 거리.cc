/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  bool flag = false;
  int firstx = -1, firsty, secondx, secondy, num;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> num;
      if (num == 1 && firstx == -1) {
        firstx = i;
        firsty = j;
      } else if(num == 1) {
        secondx = i;
        secondy = j;
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  cout << abs(firstx - secondx) + abs(firsty - secondy) << endl;

  return 0;
}