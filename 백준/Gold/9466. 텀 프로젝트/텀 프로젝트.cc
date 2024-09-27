/*
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int t, n;
int graph[MAX];
bool visited[MAX];
bool done[MAX];
int cnt = 0;

void hasCycle(int node) {
  visited[node] = true;
  int next = graph[node];

  if (!visited[next]) {
    hasCycle(next);
  } else if (!done[next]) {  // 방문했지만 아직 사이클이 아닌 경우 사이클 완성
    // 팀의 학생 수 세기
    for (int i = next; i != node; i = graph[i]) {
      cnt++;
    }
    cnt++;  // 자기 자신
  }
  done[node] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> graph[i];
    }
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        hasCycle(i);
      }
    }
    cout << n - cnt << '\n';
    cnt = 0;
    memset(visited, false, sizeof(visited));
    memset(done, false, sizeof(done));
  }

  return 0;
}