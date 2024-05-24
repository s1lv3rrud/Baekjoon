#include <bits/stdc++.h>

using namespace std;

string s;
vector<string> snum;
string sbig;
long long big;

bool cmp(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

int main(int argc, char** argv)
{
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        snum.push_back(to_string(tmp));
    }

    sort(snum.begin(), snum.end(), cmp);
    
    for (int i = 0; i < snum.size(); i++) {
        sbig += snum[i];
    }

    int idx = 0;
    while (sbig[idx] == '0') {
        idx++;
    }
    if (sbig.size() == idx) cout << 0;
    else {
        for (int i = idx; i < sbig.size(); i++) {
            cout << sbig[i];
        }
    }

    return 0;
}