#include <bits/stdc++.h>

using namespace std;

int n, maxLen = 0;
int ar[1000];
int len[1000];

void DP() {
    for (int i = 0; i < n; i++) {
        len[i] = 1;
        for (int j = i; j >= 0; j--) {
            if (ar[i] > ar[j]) {
                len[i] = max(len[i], len[j] + 1);
            }
        }
        if (maxLen < len[i]) maxLen = len[i];
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    DP();

    cout << maxLen;

    return 0;
}