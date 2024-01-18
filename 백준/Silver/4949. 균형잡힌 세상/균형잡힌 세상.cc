#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    getline(cin, input);

    while (input != ".") {
        stack<char> s;
        bool balance = true;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(' || input[i] == '[') {
                s.push(input[i]);
            }
            else if (input[i] == ')') {
                if (s.empty()) {
                    balance = false;
                    break;
                }
                else if (s.top() == '(') {
                    s.pop();
                }
                else {
                    balance = false;
                    break;
                }
            }
            else if (input[i] == ']') {
                if (s.empty()) {
                    balance = false;
                    break;
                }
                else if (s.top() == '[') {
                    s.pop();
                }
                else {
                    balance = false;
                    break;
                }
            }
        }
        if (!s.empty()) {
            balance = false;
        }

        if (balance) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }

        getline(cin, input);
    }

    return 0;
}