#include <bits/stdc++.h>

using namespace std;

int n, k, minTime = 100000;
int loc[100001];

queue<int> q;

bool IsInside(int x) {
    return 0 <= x && x <= 100000;
}

void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int nx[3] = { 2 * x, x - 1, x + 1 };
        for (int i = 0; i < 3; i++) {
            if (IsInside(nx[i])) {
                int tmp = i == 0 ? loc[x] : loc[x] + 1;
                if (nx[i] == k) {
                    if (minTime > tmp) minTime = tmp;

                }
                if (loc[nx[i]] == -1) {
                    loc[nx[i]] = tmp;
                    q.push(nx[i]);
                }
                else if (loc[nx[i]] == loc[x] + 1) {
                    if (loc[nx[i]] > tmp) loc[nx[i]] = tmp;
                    q.push(nx[i]);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if (n == k) {
        cout << 0;
        return 0;
    }

    fill(loc, loc + 100001, -1);
    loc[n] = 0;
    q.push(n);

    BFS();

    cout << minTime;

    return 0;
}