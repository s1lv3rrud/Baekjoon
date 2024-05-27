#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;

    if (n == 1) return 0;

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i << endl;
            n /= i;
        }
    }

    return 0;
}