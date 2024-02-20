#include <bits/stdc++.h>

using namespace std;

int n, k;
int stone[5001];
bool jump[5001];

string DP() {
    for (int i = 1; i < n; i++) {
        if (jump[i]) {
            for (int j = i + 1; j <= n; j++) {
                int power = (j - i) * (1 + abs(stone[i] - stone[j]));
                if (power <= k) {
                    jump[j] = true;
                }
            }
            if (jump[n]) {
                return "YES";
            }
        }
    }
    
    return "NO";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> stone[i];
    }

    fill(jump, jump + 5000, false);
    jump[1] = true;

    cout << DP();    

    return 0;
}