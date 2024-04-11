#include <bits/stdc++.h>

using namespace std;

long a, b;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int cnt = 0;
    while (a != b) {
        if (b % 2 == 0) {
            b /= 2;
            cnt++;
        }
        else if (b % 10 == 1) {
            b /= 10;
            cnt++;
        }
        else {
            cout << -1;
            return 0;
        }
        if (b < a) {
            cout << -1;
            return 0;
        }
    }

    cout << cnt + 1;

    return 0;
}