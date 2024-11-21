/*
14248 : 점프 점프
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  cin >> n;

  vector<int> v(n);
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cin >> s;

  queue<int> q;
  q.push(s - 1);
  visited[s - 1] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur + v[cur] < n && !visited[cur + v[cur]]) {
      q.push(cur + v[cur]);
      visited[cur + v[cur]] = true;
    }

    if (cur - v[cur] >= 0 && !visited[cur - v[cur]]) {
      q.push(cur - v[cur]);
      visited[cur - v[cur]] = true;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      cnt++;
    }
  }

  cout << cnt << '\n';

  return 0;
}
