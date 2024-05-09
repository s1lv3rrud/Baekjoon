#include <bits/stdc++.h>

using namespace std;

int k, q, l, v, n, p;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[8][8];

    cin >> k >> q >> l >>  v >> n >> p;

    k = 1 - k;
    q = 1 - q;
    l = 2 - l;
    v = 2 - v;
    n = 2 - n;
    p = 8 - p;

    cout << k << " " << q << " " << l << " " << v << " " << n << " " << p;

    return 0;
}