#include <bits/stdc++.h>

using namespace std;

void solve(int start, int end, int n) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }
    solve(start, 6 - start - end, n - 1);
    cout << start << " " << end << "\n";
    solve(6 - start - end, end, n - 1);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    cout << (1<<n) - 1 << "\n";
    solve(1, 3, n);

    return 0;
}