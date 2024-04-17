#include <bits/stdc++.h>

using namespace std;

char ar[3072][6144];

int dx[9] = { 0, 0, 1, 1, 2, 2, 2, 2, 2 };
int dy[9] = { 0, 0, -1, 1, -2, -1, 0, 1, 2 };

void solve(int n, int x, int y) {
    if (n == 3) {
        for (int i = 1; i < 9; i++) {
            ar[x + dx[i]][y + dy[i]] = '*';
        }
        return;
    }
    else {
        solve(n / 2, x, y);
        solve(n / 2, x + n / 2, y - n / 2);
        solve(n / 2, x + n / 2, y + n / 2);
    }

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(ar, ' ', 3072 * 6144);

    int n;
    cin >> n;

    solve(n, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            cout << ar[i][j];
        }
        cout << "\n";
    }

    return 0;
}