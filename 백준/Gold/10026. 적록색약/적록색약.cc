#include <bits/stdc++.h>

using namespace std;

int n, sum;
char ar[100][100];
bool visited[100][100];
queue<pair<int, int>> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isIn(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isIn(nx, ny) && !visited[nx][ny] && ar[nx][ny] == ar[x][y]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    
    // 적록색약이 아닌 사람
    sum = 0;
    memset(visited, 0, sizeof(bool) * 100 * 100);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                sum++;
                q.push(make_pair(i, j));
                BFS();
            }
        }
    }
    cout << sum << " ";

    // 적록색약
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ar[i][j] == 'G') {
                ar[i][j] = 'R';
            }
        }
    }
    while (!q.empty()) {
        q.pop();
    }
    sum = 0;
    memset(visited, 0, sizeof(bool) * 100 * 100);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                sum++;
                q.push(make_pair(i, j));
                BFS();
            }
        }
    }
    cout << sum;

    return 0;
}
