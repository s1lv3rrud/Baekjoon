#include <bits/stdc++.h>

using namespace std;

bool isColUsed[15]; // 열
bool isDigRToLUsed[29]; // 대각: 우측상단 -> 좌측하단
bool isDigLToRUsed[29]; // 대각: 좌측상단 -> 우측하단

int n, total = 0;
void nqueen(int cur) {
    if (cur == n) {
        total++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isColUsed[i] || isDigRToLUsed[cur + i] || isDigLToRUsed[(cur - i) + n + 1]) {
            continue;
        }
        isColUsed[i] = true;
        isDigRToLUsed[cur + i] = true;
        isDigLToRUsed[(cur - i) + n + 1] = true;
        nqueen(cur + 1);
        isColUsed[i] = false;
        isDigRToLUsed[cur + i] = false;
        isDigLToRUsed[(cur - i) + n + 1] = false;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    nqueen(0);

    cout << total;

    return 0;
}