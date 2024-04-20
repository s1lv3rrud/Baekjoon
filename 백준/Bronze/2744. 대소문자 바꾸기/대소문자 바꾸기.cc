#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 'a' - 'A';
            cout << s[i];
        }
        else {
            s[i] += 'a' - 'A';
            cout << s[i];
        }
    }

    return 0;
}