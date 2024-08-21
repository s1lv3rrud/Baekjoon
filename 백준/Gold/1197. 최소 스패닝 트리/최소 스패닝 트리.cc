/*

 */

#include <bits/stdc++.h>

using namespace std;

vector<int> parent(10001);

int find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) parent[y] = x;
}

bool sameParent(int x, int y) { return find(x) == find(y); }

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, e, res = 0;
  cin >> v >> e;

  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, {a, b}});
  }
  sort(edges.begin(), edges.end());
  for (int i = 1; i <= v; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < e; i++) {
    if (!sameParent(edges[i].second.first, edges[i].second.second)) {
      uni(edges[i].second.first, edges[i].second.second);
      res += edges[i].first;
    }
  }

  cout << res;

  return 0;
}