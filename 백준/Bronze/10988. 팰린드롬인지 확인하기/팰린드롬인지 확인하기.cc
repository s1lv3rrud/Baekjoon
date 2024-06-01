#include <bits/stdc++.h>

using namespace std;

string s, p;

int main(int argc, char** argv)
{
    cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
    {
		p.push_back(s[i]);
	}

    if (s == p) cout << 1;
	else cout << 0;
    
    return 0;
}