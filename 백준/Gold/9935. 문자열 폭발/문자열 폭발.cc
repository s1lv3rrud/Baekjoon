//

#include <bits/stdc++.h>
using namespace std;

int main() {
  string str, bomb, tmp;
  cin >> str >> bomb;

  stack<char> ans;

  for (auto s : str) {
    ans.push(s);
    if (ans.size() >= bomb.length()) {
      tmp.clear();
      for (int i = 0; i < bomb.length(); i++) {
        tmp.push_back(ans.top());
        ans.pop();
      }
      reverse(tmp.begin(), tmp.end());
      if (tmp != bomb) {
        for (int i = 0; i < tmp.length(); i++) {
          ans.push(tmp[i]);
        }
      }
    }
  }

  if (ans.empty()) {
    cout << "FRULA";
  } else {
    tmp.clear();
    while (!ans.empty()) {
      tmp.push_back(ans.top());
      ans.pop();
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp;
  }

  return 0;
}
