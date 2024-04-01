#include <bits/stdc++.h>

using namespace std;

int n, w, h;
bool escape;
char ar[1000][1000];
int visitedF[1000][1000]; // fire
int visitedS[1000][1000]; // sangeun
queue<pair<int, int>> qf;
queue<pair<int, int>> qs;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isIn(int x, int y) {
    if (x >= 0 && x < h && y >= 0 && y < w) {
        return true;
    }
    return false;
}

void BFSF() {
    while (!qf.empty()) {
        int x = qf.front().first;
        int y = qf.front().second;
        qf.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isIn(nx, ny) && (ar[nx][ny] != '#' && ar[nx][ny] != '*') && visitedF[nx][ny] == 0) {
                visitedF[nx][ny] = visitedF[x][y] + 1;
                qf.push(make_pair(nx, ny));
            }
        }
    }
}

void BFSS() {
    while(!qs.empty() && !escape) {
        int x = qs.front().first;
        int y = qs.front().second;
        qs.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!isIn(nx, ny)) {
                cout << visitedS[x][y] << "\n";
                escape = true;
                break;
            }
            if (ar[nx][ny] == '#' || ar[nx][ny] == '*') continue;
            if (visitedS[nx][ny] != 0) continue;
            if (visitedF[nx][ny] != 0 && visitedF[nx][ny] <= visitedS[x][y] + 1) continue;
            visitedS[nx][ny] = visitedS[x][y] + 1;
            qs.push(make_pair(nx, ny));
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        memset(ar, ' ', sizeof(char) * 1000 * 1000);
        memset(visitedF, 0, sizeof(int) * 1000 * 1000);
        memset(visitedS, 0, sizeof(int) * 1000 * 1000);
        while (!qf.empty()) {
            qf.pop();
        }
        while (!qs.empty()) {
            qs.pop();
        }
        escape = false;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> ar[i][j];
                if (ar[i][j] == '@') {
                    visitedS[i][j] = 1;
                    qs.push(make_pair(i, j));
                }
                else if (ar[i][j] == '*') {
                    visitedF[i][j] = 1;
                    qf.push(make_pair(i, j));
                }
            }
        }

        BFSF();
        BFSS();
        
        if (!escape) cout << "IMPOSSIBLE\n";
    }

    return 0;
}
