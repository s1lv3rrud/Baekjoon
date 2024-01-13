#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push") {
            int input;
            cin >> input;
            Q.push(input);
        }
        else if (command == "pop") {
            if (Q.empty()) cout << "-1";
            else {
                cout << Q.front();
                Q.pop();
            }
            cout << "\n";
        }
        else if (command == "size") {
            cout << Q.size();
            cout << "\n";
        }
        else if (command == "empty") {
            if (Q.empty()) cout << "1";
            else cout << "0";
            cout << "\n";
        }
        else if (command == "front") {
            if (Q.empty()) cout << "-1";
            else {
                cout << Q.front();
            }
            cout << "\n";
        }
        else if (command == "back") {
            if (Q.empty()) cout << "-1";
            else {
                cout << Q.back();
            }
            cout << "\n";

        }
    }

    return 0;
}