#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    if (a == b && a == c) {
        cout << 10000 + a * 1000;
    }
    else if (a == b) {
        cout << 1000 + b * 100;
    }
    else if (a == c) {
        cout << 1000 + c * 100;
    }
    else if (b == c) {
        cout << 1000 + b * 100;
    }
    else {
        int m = a > b ? a : b;
        m = c > m ? c : m;
        cout << m * 100;
    }

    return 0;
}
