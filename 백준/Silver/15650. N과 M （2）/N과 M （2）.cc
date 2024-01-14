#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<bool> check(9);
vector<int> print(9);

void backTracking(int index) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << print[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i] && (index == 0 || i > print[index-1])) {
            print[index] = i;
            check[i] = true;
            backTracking(index + 1);
            check[i] = false;
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    backTracking(0);

    return 0;
}