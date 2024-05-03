#include <bits/stdc++.h>

using namespace std;

string ar[5];
bool perm[25] = {};
int cnt = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool isIn(int x, int y) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5) return true;
    return false;
}

void solve() {
    do {
        queue<pair<int, int>> q;
        int dasom = 0, connect = 0;
        bool candidate[5][5] = {}, visited[5][5] = {};
        for (int i = 0; i < 25; i++) {
            if (!perm[i]) {
                int x = i / 5, y = i % 5;
                candidate[x][y] = true;
                if (q.empty()) {
                    q.push({ x, y });
                    visited[x][y] = true;
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            connect++;
            if (ar[x][y] == 'S') dasom++;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (isIn(nx, ny) && !visited[nx][ny] && candidate[nx][ny]) {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
        if (connect >= 7 && dasom >= 4) cnt++;

    } while (next_permutation(perm, perm + 25));
    return;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        cin >> ar[i];
    }

    fill(perm + 7, perm + 25, true);
    solve();

    cout << cnt;

    return 0;
}