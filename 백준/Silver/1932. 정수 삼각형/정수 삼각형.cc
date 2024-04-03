#include <bits/stdc++.h>

using namespace std;

int n;
int ar[500][500];
int sum[500][500];

void DP() {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            sum[i][j] = max(sum[i + 1][j], sum[i + 1][j + 1]) + ar[i][j];
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(sum, 0, sizeof(int) * 500 * 500);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> ar[i][j];
        }
    }
    for (int j = 0; j < n; j++) {
        cin >> ar[n - 1][j];
        sum[n - 1][j] = ar[n - 1][j];
    }

    DP();

    cout << sum[0][0];

    return 0;
}