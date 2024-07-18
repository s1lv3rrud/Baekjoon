#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    map<char, int> m;
    m['W'] = 64;
    m['H'] = 32;
    m['Q'] = 16;
    m['E'] = 8;
    m['S'] = 4;
    m['T'] = 2;
    m['X'] = 1;

    string s;
    while(cin >> s) {
        if(s == "*") break;
        int ans, current = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '/') {
                if(current == 64) ans++;
                current = 0;
            }
            current += m[s[i]];
        }
        cout << ans << "\n";
        ans = 0;
    }
}