#include <bits/stdc++.h>

using namespace std;

int t, n, rev;
deque<int> lan;
string command, input;

void parse() {
    int push = 0;
    for (int i = 1; i < input.size() - 1; i++) {
        if(input[i] == ','){
            lan.push_back(push);
            push = 0;
        }
        else {
            push *= 10;
            push += input[i] - '0';
        }
    }
    if (n != 0) {
        lan.push_back(push);
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> command;
        cin >> n;
        cin >> input;
        rev = 0;

        parse();

        bool error = false;
        for (int j = 0; j < command.size(); j++) {
            if (command[j] == 'R') {
                rev++;
            }
            else {
                if (lan.empty()) {
                    error = true;
                    break;
                }
                if (rev % 2 == 0) {
                    lan.pop_front();
                }
                else {
                    lan.pop_back();
                }
            }
        }
        if (error) {
            cout << "error\n";
        }
        else {
            if (rev % 2 != 0) {
                reverse(lan.begin(), lan.end());
            }
            cout << "[";
            if (!lan.empty()) {
                cout << lan.front();
                lan.pop_front();
            }
            while(!lan.empty()) {
                cout << "," << lan.front();
                lan.pop_front();
            }
            cout << "]\n";
        }
    }

    return 0;
}