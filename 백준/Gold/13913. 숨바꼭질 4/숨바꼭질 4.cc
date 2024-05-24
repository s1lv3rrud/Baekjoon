#include <bits/stdc++.h>

using namespace std;

int n, k;
queue<pair<int, int>> q;
stack<int> path;
bool visited[1000001];
int pre[1000001];

void solve() {
    q.push({ n, 0 });

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        visited[cur] = true;
        q.pop();
        if (cur == k) {
            int i = cur;
            while (i != n) {
                path.push(i);
                i = pre[i];
            }
            path.push(i);
            break;
        }
        // -1
        if (cur - 1 >= 0 && cur - 1 <= 200000 && visited[cur - 1] == false) {
            visited[cur - 1] = true;
            q.push({ cur - 1, cnt + 1 });
            pre[cur - 1] = cur;
        }

        // +1
        if (cur + 1 >= 0 && cur + 1 <= 200000 && visited[cur + 1] == false) {
            visited[cur + 1] = true;
            q.push({ cur + 1, cnt + 1 });
            pre[cur + 1] = cur;
        }

        // *2
        if (cur * 2 >= 0 && cur * 2 <= 200000 && visited[cur * 2] == false) {
            visited[cur * 2] = true;
            q.push({ cur * 2, cnt + 1 });
            pre[cur * 2] = cur;
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n >> k;

    solve();
    cout << path.size() - 1 << "\n";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    return 0;
}