/*
2042 구간 합 구하기
 */

#include <bits/stdc++.h>

using namespace std;

long long ar[1000000];
long long tree[4000001];  // 1번 노드부터 시작

long long makeTree(int node, int left, int right) {
  if (left == right) {
    return tree[node] = ar[left];
  }

  int mid = (left + right) / 2;

  return tree[node] = makeTree(node * 2, left, mid) +
                      makeTree(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int newIndex, long long newValue) {
  if (left == right) {
    tree[node] = newValue;
    return;
  }

  int mid = (left + right) / 2;

  if (left <= newIndex && newIndex <= mid) {
    update(node * 2, left, mid, newIndex, newValue);
  } else {
    update(node * 2 + 1, mid + 1, right, newIndex, newValue);
  }

  tree[node] = tree[node * 2] + tree[node * 2 + 1];
  return;
}

long long sum(int node, int left, int right, int start, int end) {
  if (end < left || right < start) {
    return 0;
  }

  if (start <= left && right <= end) {
    return tree[node];
  }

  int mid = (left + right) / 2;

  return sum(node * 2, left, mid, start, end) +
         sum(node * 2 + 1, mid + 1, right, start, end);
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  makeTree(1, 0, n - 1);

  for (int i = 0; i < m + k; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;

    if (a == 1) {
      update(1, 0, n - 1, b - 1, c);
    } else {
      cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
    }
  }

  return 0;
}