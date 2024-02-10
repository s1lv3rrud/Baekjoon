#include <bits/stdc++.h>

using namespace std;

int n, k;
int loc[100001];

queue<int> q;

bool IsInside(int x) {
    return 0 <= x && x <= 100000;
}

int BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int nx[3] = { x - 1, x + 1, 2 * x };
        for (int i = 0; i < 3; i++) {
            if (IsInside(nx[i])) {
                if (nx[i] == k) {
                    return loc[x] + 1;
                }
                if (loc[nx[i]] == -1) {
                    loc[nx[i]] = loc[x] + 1;
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

    cout << BFS();

    return 0;
}