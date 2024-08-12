/*

 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  deque<pair<int, int>> dq;
  for (int i = 0; i < n; i++) {
    int balloon;
    cin >> balloon;
    dq.push_back({i + 1, balloon});
  }

  while (!dq.empty()) {
    cout << dq.front().first << " ";
    int move = dq.front().second;
    dq.pop_front();
    if (dq.empty()) break;
    if (move > 0) {
      for (int i = 0; i < move - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for (int i = 0; i < abs(move); i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
}