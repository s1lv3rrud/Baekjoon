/*
보석 n개, 가방 k개 (1 <= n, k <= 300,000)
각 보석은 무게 w, 가치 v (1 <= w, v <= 1,000,000)
각 가방은 최대 무게 c (1 <= c <= 100,000,000)
가방에 담을 수 있는 최대 가격은?
최대 가격은 21억을 넘을 수 있다 (int 범위 초과) -> long long 사용
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> jewelrys(n);
  vector<int> bags(k);
  for (int i = 0; i < n; i++) {
    cin >> jewelrys[i].first >> jewelrys[i].second;
  }
  for (int i = 0; i < k; i++) {
    cin >> bags[i];
  }

  sort(jewelrys.begin(), jewelrys.end());
  sort(bags.begin(), bags.end());

  priority_queue<int> pq;
  long long ans = 0;

  int j = 0;
  for (int i = 0; i < k; i++) {
    while (j < n && jewelrys[j].first <= bags[i]) {
      pq.push(jewelrys[j++].second);
    }
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << '\n';

  return 0;
}