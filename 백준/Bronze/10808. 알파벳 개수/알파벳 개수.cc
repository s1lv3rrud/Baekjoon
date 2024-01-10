#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> num(26);
    for (int i = 0; i < s.length(); i++)
    {
        num[s[i] - 'a']++;
    }
    for (int i : num) {
        cout << i << " ";
    }

    return 0;
}