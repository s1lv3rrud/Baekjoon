#include <bits/stdc++.h>

using namespace std;

int ar[13];

int k;

void solve() {
    bool per = true;
    int pick[13];
    memset(pick, 1, sizeof(int) * 13);
    for (int i = 0; i < 6; i++) {
        pick[i] = 0;
    }
    while (per) {
        for (int i = 0; i < k; i++) {
            if(pick[i] == 0) cout << ar[i] << " ";
        }
        cout << "\n";
        per = next_permutation(pick, pick + k);
    }
    cout << "\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    while (k != 0) {
        for (int i = 0; i < k; i++) {
            cin >> ar[i];
        }

        solve();

        cin >> k;
    }



    return 0;
}