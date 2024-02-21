#include <bits/stdc++.h>

using namespace std;

int n, m;
int number[100000];
int sum[100000];
int rangei, rangej;

void DP() {
    sum[0] = number[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + number[i];
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    DP();

    for (int i = 0; i < m; i++) {
        cin >> rangei >> rangej;
        cout << sum[rangej - 1] - sum[rangei - 2] << "\n";
    }

    return 0;
}