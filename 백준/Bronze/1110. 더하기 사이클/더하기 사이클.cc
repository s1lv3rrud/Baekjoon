#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cur, cnt = 1;

    cin >> n;

    cur = (n % 10) * 10 + (n % 10 + n / 10) % 10;

    while (n != cur) {
        cur = (cur % 10) * 10 + (cur % 10 + cur / 10) % 10;
        cnt++;
    }

    cout << cnt;

    return 0;
}
