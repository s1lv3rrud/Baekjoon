#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
int dp[1500001];

void solve() {
    int end;
    for (int i = n - 1; i >= 0; i--) {
        end = i + v[i].first;
        if (end > n) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[end] + v[i].second);
        }
    }
}

int main(int argc, char** argv)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;
        v.push_back({ t, p });
    }

    solve();

    cout << dp[0];

    return 0;
}