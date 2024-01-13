#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push_front") {
            int input;
            cin >> input;
            dq.push_front(input);
        }
        else if (command == "push_back") {
            int input;
            cin >> input;
            dq.push_back(input);
        }
        else if (command == "pop_front") {
            if (dq.empty()) cout << "-1";
            else {
                cout << dq.front();
                dq.pop_front();
            }
            cout << "\n";
        }
        else if (command == "pop_back") {
            if (dq.empty()) cout << "-1";
            else {
                cout << dq.back();
                dq.pop_back();
            }
            cout << "\n";
        }
        else if (command == "size") {
            cout << dq.size();
            cout << "\n";
        }
        else if (command == "empty") {
            if (dq.empty()) cout << "1";
            else cout << "0";
            cout << "\n";
        }
        else if (command == "front") {
            if (dq.empty()) cout << "-1";
            else {
                cout << dq.front();
            }
            cout << "\n";
        }
        else if (command == "back") {
            if (dq.empty()) cout << "-1";
            else {
                cout << dq.back();
            }
            cout << "\n";

        }
    }

    return 0;
}