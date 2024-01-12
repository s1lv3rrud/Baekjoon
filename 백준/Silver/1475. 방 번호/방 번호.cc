#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> num(10);

    while (n != 0) {
        num[n % 10]++;
        n /= 10;
    }

    int max = 0;
    num[6] = (num[6] + num[9]) / 2.0 + 0.5;
    num[9] = num[6];
    cout << *max_element(num.begin(), num.end());

    return 0;
}