#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> check(8);
vector<int> print(8);

void backTracking(int index) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += check[i];
    }
    if (sum == m) {
        for (int i = 0; i < m; i++) {
            cout << print[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        print[index] = i;
        check[i]++;
        backTracking(index + 1);
        check[i]--;
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