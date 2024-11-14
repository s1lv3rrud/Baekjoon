/*
16975 수열과 쿼리 21
 */

#include <bits/stdc++.h>

using namespace std;

int ar[100000];
long long tree[400001];  // 1번 노드부터 시작

void makeTree(int node, int left, int right) {
  if (left == right) {
    tree[node] = ar[left];
    return;
  }

  int mid = (left + right) / 2;

  makeTree(node * 2, left, mid);
  makeTree(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int start, int end, int addValue) {
  if (end < left || right < start) {
    return;
  }

  if (start <= left && right <= end) {
    tree[node] += addValue;
    return;
  }

  int mid = (left + right) / 2;

  update(node * 2, left, mid, start, end, addValue);
  update(node * 2 + 1, mid + 1, right, start, end, addValue);
}

long long find(int node, int left, int right, int idx, long long sum) {
  if (idx < left || right < idx) {
    return 0;
  }

  sum += tree[node];

  if (left == right) {
    return sum;
  }

  int mid = (left + right) / 2;

  return find(node * 2, left, mid, idx, sum) +
         find(node * 2 + 1, mid + 1, right, idx, sum);
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  makeTree(1, 0, n - 1);

  int m;
  cin >> m;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int i, j, k;
      cin >> i >> j >> k;
      update(1, 0, n - 1, i - 1, j - 1, k);
    } else {
      int x;
      cin >> x;
      cout << find(1, 0, n - 1, x - 1, 0) << "\n";
    }
  }

  return 0;
}