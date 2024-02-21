#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000000] = { -1, 0 };
int path[1000000] = { -1, 0 };

void solve() {
    int min;
    for (int i = 2; i <= N; i++) {
        min = dp[i - 1] + 1;
        path[i] = i - 1;
        if (i % 3 == 0) {
            if (min > dp[i / 3] + 1) {
                min = dp[i / 3] + 1;
                path[i] = i / 3;
            }
        }
        if (i % 2 == 0) {
            if (min > dp[i / 2] + 1) {
                min = dp[i / 2] + 1;
                path[i] = i / 2;
            }
        }
        dp[i] = min;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    if (N == 1) {
        cout << 0 << "\n" << 1;
        return 0;
    }
    solve();
    cout << dp[N] << "\n";
    cout << N;

    int tmp = N;
    while (1) {
        if (path[tmp] == 1) {
            cout << " " << 1;
            break;
        }
        cout << " " << path[tmp];
        tmp = path[tmp];
    }

    return 0;
}