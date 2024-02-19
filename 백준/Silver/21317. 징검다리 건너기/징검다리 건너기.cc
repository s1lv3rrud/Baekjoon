#include <bits/stdc++.h>

using namespace std;

int n, k, minEnergy;
int stone[20][2];
int energy[20][2]; // index 0: 매우 큰 점프 X, index 1: 매우 큰 점프 O

void DP() {
    for (int i = 3; i < n; i++) {
        energy[i][0] = min(energy[i - 1][0] + stone[i - 1][0], energy[i - 2][0] + stone[i - 2][1]);
        energy[i][1] = min(min(energy[i - 1][1] + stone[i - 1][0], energy[i - 2][1] + stone[i - 2][1]), energy[i - 3][0] + k);
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> stone[i][0] >> stone[i][1];
    }

    cin >> k;

    energy[0][0] = 0;
    energy[0][1] = 0;
    energy[1][0] = stone[0][0];
    energy[1][1] = 5001;
    energy[2][0] = min(stone[0][0] + stone[1][0], stone[0][1]);
    energy[2][1] = 5001;

    DP();

    cout << min(energy[n - 1][0], energy[n - 1][1]);

    return 0;
}