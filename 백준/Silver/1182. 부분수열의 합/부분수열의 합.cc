#include <bits/stdc++.h>

using namespace std;

int ar[20];

int n, s, cnt = 0;
void solve(int cur, int total) {
    if (cur == n) {
        if (total == s) cnt++;
        return;
    }
    solve(cur + 1, total);
    solve(cur + 1, total + ar[cur]);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    if (s == 0) cnt--;

    solve(0, 0);

    cout << cnt;

    return 0;
}