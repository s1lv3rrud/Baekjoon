#include <bits/stdc++.h>

using namespace std;

int ar[64][64];

void solve(int n, int x, int y) {
    if (n == 1) {
        cout << ar[x][y];
        return;
    }
    bool zero = true, one = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (ar[i][j] == 0) one = false;
            else zero = false;
        }
    }
    if (zero) cout << 0;
    else if (one) cout << 1;
    else {
        cout << "(";
        solve(n / 2, x, y);
        solve(n / 2, x, y + n / 2);
        solve(n / 2, x + n / 2, y);
        solve(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            ar[i][j] = s[j] - '0';
        }
    }

    solve(n, 0, 0);

    return 0;
}