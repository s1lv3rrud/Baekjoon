#include <bits/stdc++.h>

using namespace std;

int r, c, result = -1;
string input;
char miro[1000][1000];
int arrayJ[1000][1000];
int arrayF[1000][1000];

queue<pair<int, int>> qJ;
queue<pair<int, int>> qF;

// 상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool IsInside(int x, int y) {
    return 0 <= x && 0 <= y && x < r&& y < c;
}

bool IsEscape(int x, int y) {
    return 0 == x || 0 == y || x == r - 1 || y == c - 1;
}

void BFSF() {
    while (!qF.empty()) {
        int x = qF.front().first;
        int y = qF.front().second;
        qF.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(nx, ny) && arrayF[nx][ny] == 0 && miro[nx][ny] == '.') {
                qF.push(make_pair(nx, ny));
                arrayF[nx][ny] = arrayF[x][y] + 1;
            }
        }
    }
}

void BFSJ() {
    while (!qJ.empty()) {
        int x = qJ.front().first;
        int y = qJ.front().second;
        qJ.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (IsInside(nx, ny) && miro[nx][ny] == '.'
                && (arrayF[nx][ny] == 0 || arrayJ[x][y] + 1 < arrayF[nx][ny])
                && arrayJ[nx][ny] == 0) {
                if (IsEscape(nx, ny)) {
                    result = arrayJ[x][y] + 1;
                    return;
                }
                arrayJ[nx][ny] = -1;
                qJ.push(make_pair(nx, ny));
                arrayJ[nx][ny] = arrayJ[x][y] + 1;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> input;
        for (int j = 0; j < c; j++) {
            miro[i][j] = input[j];
            if (miro[i][j] == 'J') {
                qJ.push(make_pair(i, j));
                arrayJ[i][j] = 1;
            }
            if (miro[i][j] == 'F') {
                qF.push(make_pair(i, j));
                arrayF[i][j] = 1;
            }
        }
    }


    int x = qJ.front().first;
    int y = qJ.front().second;
    if (IsEscape(x, y)) {
        cout << 1;
        return 0;
    }

    BFSF();
    BFSJ();

    result == -1 ? cout << "IMPOSSIBLE " : cout << result;

    return 0;
}