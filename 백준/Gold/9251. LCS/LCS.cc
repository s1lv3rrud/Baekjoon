#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int ar[1001][1001]; // ar[i][j] = s1[i - 1]까지와 s2[j - 1]까지의 LCS 길이

void DP() {
    for (int i = 1; i < s1.length() + 1; i++) {
        for (int j = 1; j < s2.length() + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) ar[i][j] = ar[i - 1][j - 1] + 1;
            else ar[i][j] = max(ar[i - 1][j], ar[i][j - 1]);
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(ar, 0, sizeof(int) * 1001 * 1001);

    cin >> s1 >> s2;

    DP();

    cout << ar[s1.length()][s2.length()];

    return 0;
}