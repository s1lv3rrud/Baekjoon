#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v, cnt = 0, ar[100];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    cin >> v;

    for (int i = 0; i < n; i++) {
        if (ar[i] == v)cnt++;
    }

    cout << cnt;

    return 0;
}