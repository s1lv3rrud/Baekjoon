#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    stack<int> S;
    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        if (input == 0) S.pop();
        else S.push(input);
    }
    int sum = 0;
    while (!S.empty()) {
        sum += S.top();
        S.pop();
    }
    cout << sum;

    return 0;
}