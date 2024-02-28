#include <bits/stdc++.h>

using namespace std;

int n, m;
int ar[1000001];

int getParent(int a) {
    if (ar[a] == a) return a;
    return ar[a] = getParent(ar[a]);
}

void unionFunc(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a > b) ar[a] = b;
    else ar[b] = a;
}

void findFunc(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) cout << "yes\n";
    else cout << "no\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        ar[i] = i;
    }

    int cmd[3];
    for (int i = 0; i < m; i++) {
        cin >> cmd[0] >> cmd[1] >> cmd[2];
        if (cmd[0] == 0) {
            unionFunc(cmd[1], cmd[2]);
        }
        else {
            findFunc(cmd[1], cmd[2]);
        }

    }


    return 0;
}