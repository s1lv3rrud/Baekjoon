#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  // 우선순위 큐를 사용하여 중요도가 높은 일부터 처리
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    pq.push(d[i]);
  }

  int days = 0;
  int satisfaction = 0;
  vector<int> satisfaction_per_day;

  while (!pq.empty()) {
    int current_task = pq.top();
    pq.pop();

    // 만족감 계산
    satisfaction = floor(satisfaction / 2) + current_task;
    satisfaction_per_day.push_back(satisfaction);
    days++;

    // 중요도 감소 후 완료되지 않았다면 다시 큐에 삽입
    current_task -= m;
    if (current_task > k) {
      pq.push(current_task);
    }
  }

  // 결과 출력
  cout << days << "\n";
  for (int i = 0; i < satisfaction_per_day.size(); i++) {
    cout << satisfaction_per_day[i] << "\n";
  }

  return 0;
}