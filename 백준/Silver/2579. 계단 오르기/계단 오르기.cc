#include <bits/stdc++.h>

using namespace std;

int n;
int stairs[300];
int score[300][2];

void DP() {
    for (int i = 2; i < n; i++) {
        score[i][0] = max(score[i - 2][0], score[i - 2][1]) + stairs[i];
        score[i][1] = score[i - 1][0] + stairs[i];
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    score[0][0] = stairs[0];
    score[0][1] = 0;
    score[1][0] = stairs[1];
    score[1][1] = stairs[0] + stairs[1];

    DP();


    cout << max(score[n - 1][0], score[n - 1][1]);

    return 0;
}