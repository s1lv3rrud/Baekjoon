#include <bits/stdc++.h>

using namespace std;

int n, maxResult = -1000000000, minResult = 1000000000;
vector<int> a;
vector<int> op_num(4); //  + - x /
vector<int> op;
vector<bool> check;

void backtracking(vector<int> order) {
    if (order.size() == n) {
        int calc = a[0];
        for (int i = 1; i < n; i++) {
            switch (order[i]) {
            case 1:
                calc += a[i];
                break;
            case 2:
                calc -= a[i];
                break;
            case 3:
                calc *= a[i];
                break;
            case 4:
                calc /= a[i];
                break;
            }
        }
        maxResult = max(calc, maxResult);
        minResult = min(calc, minResult);
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (!check[i]) {
            check[i] = true;
            order.push_back(op[i]);
            backtracking(order);
            check[i] = false;
            order.pop_back();
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < 4; i++) {
        cin >> op_num[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < op_num[i]; j++) {
            op.push_back(i + 1);
            check.push_back(false);
        }
    }

    vector<int> order = { 0 }; // index 0은 사용 안 함

    backtracking(order);

    cout << maxResult << "\n" << minResult;
    return 0;
}