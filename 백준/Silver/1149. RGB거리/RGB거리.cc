#include <bits/stdc++.h>

using namespace std;

int n;
int rgb[1000][3];
int cost[1000][3];

void DP() {
    for (int i = 1; i < n; i++) {
        cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + rgb[i][0];
        cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + rgb[i][1];
        cost[i][2] = min(cost[i - 1][1], cost[i - 1][0]) + rgb[i][2];
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    cost[0][0] = rgb[0][0];
    cost[0][1] = rgb[0][1];
    cost[0][2] = rgb[0][2];

    DP();

    int result = cost[n - 1][0];
    result = min(result, cost[n - 1][1]);
    result = min(result, cost[n - 1][2]);

    cout << result;

    return 0;
}