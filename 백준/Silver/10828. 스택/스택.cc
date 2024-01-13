#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string input;
    stack<int> S;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "push") {
            int push;
            cin >> push;
            S.push(push);
        }
        else if (input == "pop") {
            if (!S.empty()) {
                cout << S.top(); 
                S.pop();
            }
            else cout << -1;
            cout << "\n";
        }
        else if (input == "size") {
            cout << S.size();
            cout << "\n";

        }
        else if (input == "empty") {
            if (S.empty()) cout << 1;
            else cout << 0;
            cout << "\n";
        }
        else if (input == "top") {
            if (!S.empty()) cout << S.top();
            else cout << -1;
            cout << "\n";
        }
    }

    return 0;
}