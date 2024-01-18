#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;

    string input;
    cin >> input;

    int total = 0, mul = 1;
    for (int i = 0; i < input.length(); i++) {
        switch (input[i]) {
        case '(':
            s.push(input[i]);
            mul *= 2;
            break;

        case '[':
            s.push(input[i]);
            mul *= 3;
            break;

        case ')':
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            s.pop();
            if (input[i - 1] == '(') {
                total += mul;
            }
            mul /= 2;
            break;

        case ']':
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            s.pop();
            if (input[i - 1] == '[') {
                total += mul;
            }
            mul /= 3;
            break;
        }
    }
    if (s.empty()) {
        cout << total;
    }
    else {
        cout << 0;
    }

    return 0;
}