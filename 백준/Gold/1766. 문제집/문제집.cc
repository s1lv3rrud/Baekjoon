/*

 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> problems(n + 1);
  vector<int> indegree(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    problems[a].push_back(b);
    indegree[b]++;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  // 난이도 별 우선순위 정렬
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      pq.push(i);
    }
  }

  vector<int> res;
  // 위상정렬
  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();
    res.push_back(cur);
    for (int i = 0; i < problems[cur].size(); i++) {
      indegree[problems[cur][i]]--;
      if (indegree[problems[cur][i]] == 0) {
        pq.push(problems[cur][i]);
      }
    }
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}