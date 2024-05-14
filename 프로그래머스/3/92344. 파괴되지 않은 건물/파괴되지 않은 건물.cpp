#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    int answer = 0;

    vector<vector<int>> accSum;
    accSum.resize(1001, vector<int>(1001, 0));

    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0], r1 = skill[i][1], c1 = skill[i][2], 
            r2 = skill[i][3], c2 = skill[i][4], degree = type == 1 ? -skill[i][5] : skill[i][5];
        
         accSum[r1][c1] += degree;
        accSum[r2 + 1][c2 + 1] += degree;
        accSum[r1][c2 + 1] -= degree;
        accSum[r2 + 1][c1] -= degree;
    }

    // 최종 누적합
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y < m; y++) {
            accSum[x][y + 1] += accSum[x][y];
        }
    }
    for (int y = 0; y <= m; y++) {
        for (int x = 0; x < n; x++) {
            accSum[x + 1][y] += accSum[x][y];
        }
    }

    // answer
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (board[x][y] + accSum[x][y] >= 1) {
                answer++;
            }
        }
    }

    return answer;
}