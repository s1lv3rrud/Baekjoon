#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0; // 깨진 계란 개수
int res = 0;
int s[8];
int w[8];

void solve(int cur) {
    if (cur == n) {
        res = max(res, cnt);
        return;
    }
    if (s[cur] <= 0 || cnt == n - 1) {
        solve(cur + 1);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == cur || s[i] <= 0) {
            continue;
        }
        s[cur] -= w[i];
        s[i] -= w[cur];
        if (s[cur] <= 0) cnt++;
        if (s[i] <= 0) cnt++;
        solve(cur + 1);
        if (s[cur] <= 0) cnt--;
        if (s[i] <= 0) cnt--;
        s[cur] += w[i];
        s[i] += w[cur];
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }

    solve(0);

    cout << res;

    return 0;
}