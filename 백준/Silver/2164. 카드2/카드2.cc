#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        Q.push(i);
    }
    while (Q.size() != 1) {
        Q.pop();
        int second = Q.front();
        Q.pop();
        Q.push(second);
    }
    cout << Q.front();

    return 0;
}