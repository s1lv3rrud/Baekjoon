#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>

int dp[1000000] = { -1, 0};
int N;
void solve() {
    int min;

    for (int i = 2; i <= N; i++) {
        min = dp[i - 1] + 1;
        if (i % 3 == 0) {
            if (min > dp[i / 3] + 1) {
                min = dp[i / 3] + 1;
            }
        }
        if (i % 2 == 0) {
            if (min > dp[i / 2] + 1) {
                min = dp[i / 2] + 1;
            }
        }
        dp[i] = min;
    }
}

int main() {
    scanf("%d", &N);
    solve();
    printf("%d", dp[N]);
}