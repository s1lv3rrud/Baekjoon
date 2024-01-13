#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    char c;
    int n, m, i;
    list<char> editor;

    cin >> input;
    for (auto i : input) editor.push_back(i);
    auto it = editor.end();
    cin >> m;

    for (i = 0; i < m; i++) {
        cin >> c;
        switch (c) {
        case 'L':
            if (it != editor.begin()) it--;
            break;
        case 'D':
            if (it != editor.end()) it++;
            break;
        case 'B':
            if (it != editor.begin()) {
                it--;
                it = editor.erase(it);
            }
            break;
        case 'P':
            char plus;
            cin >> plus;
            editor.insert(it, plus);
            break;
        }
    }
    
    for (auto e : editor) cout << e;

    return 0;
}