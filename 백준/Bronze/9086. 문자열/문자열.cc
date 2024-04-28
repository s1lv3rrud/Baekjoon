#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << s[0] << s[s.size() - 1] << "\n";
    };

    return 0;
}