/*
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int N, M, X, v1, v2;
vector<pair<int, int>> vertex[MAX];
priority_queue<pair<int, int>> pq;
int dist[MAX];
int goDist[MAX];

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

  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    vertex[a].push_back({b, c});
  }

  for (int i = 1; i <= N; i++) {
    dijkstra(i);
    goDist[i] = dist[X];
  }

  dijkstra(X);

  int maxDist = dist[1] + goDist[X];
  for (int i = 2; i <= N; i++) {
    maxDist = max(maxDist, dist[i] + goDist[i]);
  }
  cout << maxDist << '\n';

  return 0;
}
