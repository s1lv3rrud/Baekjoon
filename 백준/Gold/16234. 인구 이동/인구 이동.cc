#include <bits/stdc++.h>

using namespace std;

int n, l, r, result = 0;
int ground[50][50];
bool visited[50][50];

queue<pair<int, int>> q;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool IsInside(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < n;
}

int BFS(int startX, int startY) {
    vector<pair<int, int>> unionV;
    unionV.push_back(make_pair(startX, startY));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(nx, ny) && !visited[nx][ny]) {
                int sub = abs(ground[x][y] - ground[nx][ny]);
                if (sub >= l && sub <= r) {
                    q.push(make_pair(nx, ny));
                    unionV.push_back(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }

    int unionSize = unionV.size();
    int move = 0;
    for(int i = 0; i < unionSize; i++) {
        int x = unionV[i].first;
        int y = unionV[i].second;
        move += ground[x][y];
    }
    move /= unionSize;
    for (int i = 0; i < unionSize; i++) {
        int x = unionV[i].first;
        int y = unionV[i].second;
        ground[x][y] = move;
    }

    return unionSize;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ground[i][j];
        }
    }

    while (true) {
        bool flag = false;
        memset(visited, false, 50 * 50);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                    if (BFS(i, j) != 1) {
                        flag = true;
                    }
                }
            }
        }
        if (!flag) break;
        result++;
    }

    cout << result;
    return 0;
}