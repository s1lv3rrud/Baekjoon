#include <bits/stdc++.h>

using namespace std;

char ar[6561][6561];

int dx[10] = { 0, 0, 0, 0, 1, 1, 1, 2, 2, 2 };
int dy[10] = { 0, 0, 1, 2, 0, 1, 2, 0, 1, 2 };

void solve(int n, int x, int y, int cnt) {
    if (n == 1) {
        if (cnt != 5) {
            ar[x][y] = '*';
        }
        else {
            ar[x][y] = ' ';
        }
        return;
    }

    if (cnt == 5) {
        for (int i = 1; i <= 9; i++) {
            solve(n / 3, x + n / 3 * dx[i], y + n / 3 * dy[i], 5);
        }
    }
    else {
        for (int i = 1; i <= 9; i++) {
            solve(n / 3, x + n / 3 * dx[i], y + n / 3 * dy[i], i);
        }
    }

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve(n, 0, 0, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ar[i][j];
        }
        cout << "\n";
    }

    return 0;
}