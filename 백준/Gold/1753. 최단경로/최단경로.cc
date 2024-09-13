/*
 */

#include <bits/stdc++.h>

using namespace std;

int V, E, start;
vector<pair<int, int>> vertex[20001];
priority_queue<pair<int, int>> pq;
int dist[20001];

void dijkstra() {
  fill(dist, dist + 20001, 1e9);
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    for (int i = 0; i < vertex[cur].size(); i++) {
      int next = vertex[cur][i].first;
      int nextCost = vertex[cur][i].second;

      if (dist[next] > cost + nextCost) {
        dist[next] = cost + nextCost;
        pq.push({-dist[next], next});
      }
    }
  }
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;
  cin >> start;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vertex[a].push_back({b, c});
  }
  dijkstra();

  for (int i = 1; i <= V; i++) {
    if (dist[i] == 1e9)
      cout << "INF\n";
    else
      cout << dist[i] << '\n';
  }

  return 0;
}
