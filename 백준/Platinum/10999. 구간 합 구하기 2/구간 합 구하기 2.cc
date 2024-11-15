/*
10999 구간 합 구하기 2
 */

#include <bits/stdc++.h>

using namespace std;

long long ar[1000000];
long long tree[4000001];  // 1번 노드부터 시작
long long lazy[4000001];

long long makeTree(int node, int left, int right) {
  if (left == right) {
    return tree[node] = ar[left];
  }

  int mid = (left + right) / 2;

  return tree[node] = makeTree(node * 2, left, mid) +
                      makeTree(node * 2 + 1, mid + 1, right);
}

void propagate(int node, int left, int right) {
  if (lazy[node] != 0) {
    tree[node] += (right - left + 1) * lazy[node];

    if (left != right) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
  }
}

void update(int node, int left, int right, int start, int end,
            long long addValue) {
  propagate(node, left, right);
  if (end < left || right < start) {
    return;
  }

  if (start <= left && right <= end) {
    tree[node] += (right - left + 1) * addValue;
    if (left != right) {
      lazy[node * 2] += addValue;
      lazy[node * 2 + 1] += addValue;
    }
    return;
  }

  int mid = (left + right) / 2;

  update(node * 2, left, mid, start, end, addValue);
  update(node * 2 + 1, mid + 1, right, start, end, addValue);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long find(int node, int left, int right, int start, int end) {
  propagate(node, left, right);
  if (end < left || right < start) {
    return 0;
  }

  if (start <= left && right <= end) {
    return tree[node];
  }

  int mid = (left + right) / 2;

  return find(node * 2, left, mid, start, end) +
         find(node * 2 + 1, mid + 1, right, start, end);
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

  long long a, b, c, d;
  for (int i = 0; i < m + k; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      update(1, 0, n - 1, b - 1, c - 1, d);
    } else {
      cin >> b >> c;
      cout << find(1, 0, n - 1, b - 1, c - 1) << '\n';
    }
  }

  return 0;
}