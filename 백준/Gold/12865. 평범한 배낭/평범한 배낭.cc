#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<int, int>> vec;
int bag[101][100001];

void DP() {
    for (int cap = 1; cap < k + 1; cap++) {
        // capacity
        for (int i = 1; i < n + 1; i++) {
            int w = vec[i - 1].first;
            int v = vec[i - 1].second;

            if (w <= cap) {
                bag[i][cap] = max(bag[i - 1][cap], bag[i - 1][cap - w] + v);
            }
            else {
                bag[i][cap] = bag[i - 1][cap];
            }
        }

    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(bag, 0, sizeof(int) * 101 * 100001);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({ a, b });
    }

    DP();

    cout << bag[n][k];

    return 0;
}