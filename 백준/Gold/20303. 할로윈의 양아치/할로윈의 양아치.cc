/*
20303 할로윈의 양아치
스브러스가 다른 아이들의 사탕을 빼앗는다
스크러스는 한 아이의 사탕을 뺏으면 그 아이 친구들의 사탕도 뺏는다
k명 이상의 아이들이 울기 시작하면 울음소리가 공명하여 어른들에게 들킨다
최대로 뺏을 수 있는 양을 구해라
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> c;
vector<int> parent(30001);
vector<int> childs(30001);
vector<int> dp(3001);

int find(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = find(parent[x]);
}

void union_parent(int a, int b) {
  a = find(a);
  b = find(b);
  if (a > b) {
    swap(a, b);
  }
  parent[b] = a;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  c.resize(n + 1);

  // candy 입력 및 childs 초기화
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    parent[i] = i;
    childs[i] = 1;
  }

  // parent 초기화
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    union_parent(a, b);
  }

  // 각 그룹의 사탕 개수와 아이 수 갱신
  for (int i = 1; i <= n; i++) {
    if(parent[i] == i) continue;
    int p = find(i);
    c[p] += c[i];
    childs[p] += childs[i];
  }

  // dp 초기화
  for (int i = 1; i <= n; i++) {
    if (parent[i] != i) continue;
    for (int j = k - 1; j - childs[i] >= 0; j--) {
      dp[j] = max(dp[j], dp[j - childs[i]] + c[i]);
    }
  }

  cout << dp[k - 1];

  return 0;
}