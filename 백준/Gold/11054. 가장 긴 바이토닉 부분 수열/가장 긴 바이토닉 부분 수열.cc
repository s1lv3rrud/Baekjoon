#include <bits/stdc++.h>

using namespace std;

int n;
int s[1001];
int front[1001];
int back[1001];

void DP() {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i; j++) {
            if (s[i] > s[j] && front[j] + 1 > front[i]) {
                front[i] = front[j] + 1;
            }
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = n; j > i; j--) {
            if (s[i] > s[j] && back[j] + 1 > back[i]) {
                back[i] = back[j] + 1;
            }
        }
    }
}

int calBitonic() {
    int maxLen = 0;
    for (int i = 1; i < n + 1; i++) {
        if (front[i] + back[i] > maxLen) maxLen = front[i] + back[i];
    }

    return maxLen + 1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(front, 0, sizeof(int) * 1001);
    memset(back, 0, sizeof(int) * 1001);

    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        cin >> s[i];
    }

    DP();

    cout << calBitonic();

    return 0;
}