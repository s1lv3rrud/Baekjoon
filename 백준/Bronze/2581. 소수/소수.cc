#include <bits/stdc++.h>

using namespace std;

bool isSosu(int a) {
	if (a == 1) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) return false;
	}
	return true;

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, sum = 0, min = INT_MAX;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        bool res = isSosu(i);
		if (res) {
			sum += i;
			if (min > i) min = i;
		}
    }

	if (sum == 0) cout << -1;
	else cout << sum << "\n" << min;

    return 0;
}