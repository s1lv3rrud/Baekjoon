#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, num = 0;
    cin >> n;

    vector<bool> check(2000001);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        check[a] = true;
    }

    cin >> x;

    for (int i = 1; i < (x + 1)/2; i++) {
        if (check[i] && check[x - i]) num++;
    }

    cout << num;

    return 0;
}