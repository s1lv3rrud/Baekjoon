#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<int, int>> S;
    S.push({ 100000001, 0 });
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        while (input > S.top().first)
            S.pop();
        cout << S.top().second << " ";
        S.push({input, i});
    }

    return 0;
}