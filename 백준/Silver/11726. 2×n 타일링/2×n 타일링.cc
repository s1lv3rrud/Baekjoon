#include <bits/stdc++.h>

using namespace std;

int n;
int cost[1000];

void DP() {
    for (int i = 2; i < n; i++) {
        cost[i] = cost[i - 1] + cost[i - 2];
        cost[i] %= 10007;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cost[0] = 1;
    cost[1] = 2;

    DP();

    cout << cost[n - 1];

    return 0;
}