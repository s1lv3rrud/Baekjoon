#include <bits/stdc++.h>

using namespace std;

int solve(int n, int r, int c) {
    if (n == 0) return 0;
    int half = pow(2, n - 1);
    if (r >= 0 && r < half && c >= 0 && c < half) {
        return solve(n - 1, r, c);
    }
    else if (r >= 0 && r < half && c < pow(2, n) && c >= half) {
        return half * half + solve(n - 1, r, c - half);
    }
    else if (r < pow(2, n) && r >= half && c >= 0 && c < half) {
        return 2 * half * half + solve(n - 1, r - half, c);
    }
    else {
        return 3 * half * half + solve(n - 1, r - half, c - half);
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;
    cout << solve(n, r, c);

    return 0;
}