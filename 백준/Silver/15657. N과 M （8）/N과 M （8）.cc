#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> input(9);
vector<int> check(9);
vector<int> print(9);

void backTracking(int index) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += check[i];
    }
    // 탐색 종료 조건
    if (sum == m) {
        for (int i = 0; i < m; i++) {
            cout << print[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (index == 0 || input[i] >= print[index - 1]) {
            print[index] = input[i];
            check[i]++;
            backTracking(index + 1);
            check[i]--;
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.begin() + n + 1);

    backTracking(0);

    return 0;
}