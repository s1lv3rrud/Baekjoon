#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool isIn(int n, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int solution(vector<vector<int>> board) {
    int n = board.size(), answer = INT_MAX;
    int cost[25][25][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                cost[i][j][k] = INT_MAX;
            }
        }
    }

    // x, y, cost, dir
    queue<tuple<int, int, int, int>> q;

    q.push({ 0, 0, 0, -1}); // dir 미정: -1
    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    cost[0][0][2] = 0;
    cost[0][0][3] = 0;

    while (!q.empty()) {
        int x, y, curCost, dir;
        tie(x, y, curCost, dir) = q.front();
        q.pop();

        if (x == n - 1 && y == n - 1) {
            answer = *min_element(cost[n - 1][n - 1], cost[n - 1][n - 1] + 4);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isIn(n, nx, ny)) continue;
            if (board[nx][ny] == 1) continue;

            int newCost;
            if (dir == -1 || dir == i) { 
                newCost = curCost + 100;
            }
            else {
                newCost = curCost + 100 + 500;
            }

            if (cost[nx][ny][i] > newCost) {
                cost[nx][ny][i] = newCost;
                q.push({ nx, ny, newCost, i });
            }
        }
    }

    return answer;
}