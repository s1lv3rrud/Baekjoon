#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, ans;
    cin >> a >> b;
    ans = a * b;

    while (b != 0) {
        cout << a * (b % 10) << "\n";
        b /= 10;
    }

    cout << ans;

    return 0;
}