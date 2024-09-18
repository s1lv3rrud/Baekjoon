/*
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int N, M, X;
vector<pair<int, int>> vertex[MAX];
priority_queue<pair<int, int>> pq;
vector<int> ans(MAX);

void dijkstra(int start) {
  vector<int> dist(MAX, 1e9);
  pq.push({0, start});

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if (dist[cur] < cost) continue;
    for (int i = 0; i < vertex[cur].size(); i++) {
      int next = vertex[cur][i].first;
      int nextCost = vertex[cur][i].second;

      if (dist[next] > cost + nextCost) {
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }
  ans = dist;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vertex[a].push_back({b, c});
  }

  for (int i = 1; i <= N; i++) {
    dijkstra(i);
    for (int j = 1; j <= N; j++) {
      if (ans[j] == 1e9 || i == j)
        cout << "0 ";
      else
        cout << ans[j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
