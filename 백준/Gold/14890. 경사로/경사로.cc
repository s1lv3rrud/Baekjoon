#include <bits/stdc++.h>

using namespace std;

int n, l;
vector<vector<int>> board(100, vector<int>(100));

bool canPlaceSlope(vector<int>& line) {
    vector<bool> installed(n, false);  // 경사로 설치 여부 확인 배열
    
    for (int i = 0; i < n - 1; i++) {
        if (line[i] == line[i + 1]) continue;  // 높이가 같으면 통과

        if (abs(line[i] - line[i + 1]) > 1) return false;  // 높이 차이가 1보다 크면 불가능

        if (line[i] < line[i + 1]) {  // 높이가 낮은 곳에서 높은 곳으로
            if (i - l + 1 < 0) return false;  // 경사로를 놓을 공간이 부족한 경우
            for (int j = i; j > i - l; j--) {
                if (line[j] != line[i] || installed[j]) return false;  // 경사로 설치 조건 불충족
                installed[j] = true;  // 경사로 설치
            }
        } else {  // 높이가 높은 곳에서 낮은 곳으로
            if (i + l >= n) return false;  // 경사로를 놓을 공간이 부족한 경우
            for (int j = i + 1; j <= i + l; j++) {
                if (line[j] != line[i + 1] || installed[j]) return false;  // 경사로 설치 조건 불충족
                installed[j] = true;  // 경사로 설치
            }
        }
    }

    return true;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    // row
    for (int i = 0; i < n; i++) {
        if (canPlaceSlope(board[i])) ans++;
    }

    // col
    for (int i = 0; i < n; i++) {
        vector<int> col(n);
        for (int j = 0; j < n; j++) {
            col[j] = board[j][i];
        }
        if (canPlaceSlope(col)) ans++;
    }

    cout << ans;

    return 0;
}
