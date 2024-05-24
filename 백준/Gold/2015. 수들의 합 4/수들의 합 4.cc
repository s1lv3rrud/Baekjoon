#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(int argc, char** argv)
{
    cin >> n >> k;
    int ar[200001];
    ar[0] = 0;
    map<int, long long> m;
    long long ans = 0;

    for (int i = 1; i < n + 1; i++) {
        cin >> ar[i];
        ar[i] += ar[i - 1];
        if (ar[i] == k) ans++;
    }

    // ar[j]-ar[i-1]=k, ar[i-1]=ar[j]-k
    for (int i = 1; i < n + 1; i++) {
        ans += m[ar[i] - k];
        m[ar[i]]++;
    }

    cout << ans;

    return 0;
}