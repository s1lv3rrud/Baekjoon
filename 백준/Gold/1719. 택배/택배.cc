/*
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 2001

int N, M, X;
vector<pair<int, int>> vertex[MAX];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> ans(MAX, {1e9, 0});

void dijkstra(int start) {
  vector<pair<int, int>> dist(MAX, {1e9, 0});
  pq.push({0, start});
  dist[start].second = start;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if (dist[cur].first < cost) continue;
    for (int i = 0; i < vertex[cur].size(); i++) {
      int next = vertex[cur][i].first;
      int nextCost = vertex[cur][i].second;

      if (dist[next].first > cost + nextCost) {
        dist[next].first = cost + nextCost;
        dist[next].second = cur;
        pq.push({-dist[next].first, next});
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
    vertex[b].push_back({a, c});
  }

  vector<vector<int>> res(N + 1, vector<int>(N + 1));

  for (int i = 1; i <= N; i++) {
    dijkstra(i);
    for (int j = 1; j <= N; j++) {
      res[j][i] = ans[j].second;
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j)
        cout << "- ";
      else
        cout << res[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
