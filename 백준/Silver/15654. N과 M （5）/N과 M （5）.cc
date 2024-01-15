#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> input(9);
vector<int> check(9);
vector<int> print(9);

void backTracking(int index) {
    // 탐색 종료 조건
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << print[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            print[index] = input[i];
            check[i] = true;
            backTracking(index + 1);
            check[i] = false; // 이전 상태로 돌아가기(Back)
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