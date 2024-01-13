#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num = 1;
    cin >> n;
    stack<int> S;
    string result;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (S.empty()) {
            S.push(num);
            result.append("+");
            num++;
        }
        if (S.top() < input) {
            while (S.top() != input) {
                S.push(num);
                result.append("+");
                num++;
            }
        }
        else if (S.top() > input) {
            break;
        }
        S.pop();
        result.append("-");
    }
    if (S.empty()) {
        for (int i = 0; i < result.length(); i++) {
            cout << result[i] << "\n";
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}