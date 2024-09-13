/*
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int N, E, v1, v2;
vector<pair<int, int>> vertex[MAX];
priority_queue<pair<int, int>> pq;
int dist[MAX];

void dijkstra(int start) {
  fill(dist, dist + MAX, 1e9);
  pq.push({0, start});
  dist[start] = 0;

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
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vertex[a].push_back({b, c});
    vertex[b].push_back({a, c});
  }

  cin >> v1 >> v2;

  long long int v1Ans, v2Ans;
  dijkstra(1);
  v1Ans = dist[v1];
  v2Ans = dist[v2];
  dijkstra(v1);
  v1Ans += dist[v2];
  v2Ans += dist[N];
  dijkstra(v2);
  v1Ans += dist[N];
  v2Ans += dist[v1];

  if (v1Ans >= 1e9 && v2Ans >= 1e9)
    cout << -1 << '\n';
  else
    cout << min(v1Ans, v2Ans) << '\n';

  return 0;
}
