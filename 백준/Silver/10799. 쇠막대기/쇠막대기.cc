#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;

    string input;
    cin >> input;

    int num = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            if (input[i + 1] == ')') {
                // 레이저인 경우
                num += s.size();
                i++;
            }
            else {
                s.push(input[i]);
            }
        }
        else {
            num++;
            s.pop();
        }
    }
    cout << num;

    return 0;
}