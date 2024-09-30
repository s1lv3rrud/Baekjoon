/*
1107 리모컨
 */

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> buttons;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    buttons.push_back(b);
  }

  int cur = 100;

  // 1. +, - 버튼만으로 이동하는 경우
  int cnt = abs(n - cur);

  // 2. 숫자 버튼을 눌러 이동하는 경우
  for (int i = 0; i <= 1000000; i++) {
    string s = to_string(i);
    bool flag = false;
    for (int j = 0; j < s.size(); j++) {
      for (int k = 0; k < buttons.size(); k++) {
        if (s[j] == buttons[k] + '0') { // 고장난 버튼을 누르는 경우
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) { // 고장난 버튼을 누르지 않는 경우
      cnt = min(cnt, abs(n - i) + (int)s.size());
    }
  }

  cout << cnt;

  return 0;
}