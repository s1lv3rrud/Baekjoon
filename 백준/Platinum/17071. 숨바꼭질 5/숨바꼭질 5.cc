#include <bits/stdc++.h>

using namespace std;

int n, k;
queue<pair<int, int>> q;
// 짝수초/홀수초인 경우를 구분해주어야 함
bool visited[2][5000001];

int solve() {
    q.push({ n, 0 });

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        visited[cnt % 2][cur] = true;
        q.pop();
        int sister = k + cnt * (cnt + 1) / 2;
        if (sister > 500000) return -1;
        if (visited[cnt % 2][sister]) return cnt;
        cnt++;
        // -1
        if (cur - 1 >= 0 && cur - 1 <= 500000 && visited[cnt % 2][cur - 1] == false) {
            visited[cnt % 2][cur - 1] = true;
            q.push({ cur - 1, cnt });
        }

        // +1
        if (cur + 1 >= 0 && cur + 1 <= 500000 && visited[cnt % 2][cur + 1] == false) {
            visited[cnt % 2][cur + 1] = true;
            q.push({ cur + 1, cnt });
        }

        // *2
        if (cur * 2 >= 0 && cur * 2 <= 500000 && visited[cnt % 2][cur * 2] == false) {
            visited[cnt % 2][cur * 2] = true;
            q.push({ cur * 2, cnt });
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n >> k;
    
    cout << solve();

    return 0;
}