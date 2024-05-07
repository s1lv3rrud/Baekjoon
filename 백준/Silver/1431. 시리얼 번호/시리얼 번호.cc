#include <bits/stdc++.h>

using namespace std;

int n;
string ar[50];

bool cmp(const string& a, const string& b) {
    int al = a.length(), bl = b.length();
    if (al == bl) {
        int as = 0, bs = 0; // sum
        for (int i = 0; i < al; i++) {
            if(a[i] >= '0' && a[i] <= '9') as += int(a[i] - '0');
        }
        for (int i = 0; i < bl; i++) {
            if (b[i] >= '0' && b[i] <= '9') bs += int(b[i] - '0');
        }
        if (as == bs) {
            return a < b;
        }
        return as < bs;
    }
    return a.length() < b.length();
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    sort(ar, ar + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << ar[i] << "\n";
    }

    return 0;
}