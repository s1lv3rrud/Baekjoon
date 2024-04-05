#include <bits/stdc++.h>

using namespace std;

int n, m, maxSafe = 0;
int ar[8][8];
int tmp[8][8];

queue<pair<int, int>> virusQ;
vector<pair<int, int>> emptyV;

int dx[8] = { 1, -1, 0, 0 };
int dy[8] = { 0, 0, 1, -1 };

bool isIn(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

int countSafe() {
    int safe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) {
                safe++;
            }
        }
    }
    return safe;
}

void spread() {
    queue<pair<int, int>> tmpVirusQ;
    tmpVirusQ = virusQ;
    while (!tmpVirusQ.empty()) {
        int x = tmpVirusQ.front().first;
        int y = tmpVirusQ.front().second;
        tmpVirusQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isIn(nx, ny) && tmp[nx][ny] == 0) {
                tmp[nx][ny] = 2;
                tmpVirusQ.push({ nx, ny });
            }
        }
    }
}

void BFS() {
    queue<pair<int, int>> tmpVirusQ;
    tmpVirusQ = virusQ;
    for (int i = 0; i < emptyV.size(); i++) {
        for (int j = i + 1; j < emptyV.size(); j++) {
            for (int k = j + 1; k < emptyV.size(); k++) {
                auto a = emptyV[i];
                auto b = emptyV[j];
                auto c = emptyV[k];

                memcpy(tmp, ar, sizeof(int) * 8 * 8);

                tmp[a.first][a.second] = 1;
                tmp[b.first][b.second] = 1;
                tmp[c.first][c.second] = 1;

                spread();

                maxSafe = max(maxSafe, countSafe());
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 2) {
                virusQ.push({ i, j });
            }
            else if (ar[i][j] == 0) {
                emptyV.push_back({ i, j });
            }
        }
    }

    BFS();

    cout << maxSafe;

    return 0;
}