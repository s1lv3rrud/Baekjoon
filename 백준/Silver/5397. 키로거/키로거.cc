#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string input;
    for (int i = 0; i < n; i++) {
        list<char> password;
        cin >> input;
        auto cursor = password.begin();
        for (int j = 0; j < input.length(); j++) {
            switch (input[j]) {
            case '<':
                if (cursor != password.begin()) cursor--;
                break;
            case '>':
                if (cursor != password.end()) cursor++;
                break;
            case '-':
                if (cursor != password.begin()) {
                    cursor--;
                    cursor = password.erase(cursor);
                }
                break;
            default:
                password.insert(cursor, input[j]);
                break;
            }
        }

        for (auto p : password) cout << p;
        cout << "\n";
    }

    return 0;
}