#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n, ar[1000], avg;
	cin >> c;

    while (c--) {
		int avg = 0;
		double cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			avg += ar[i];
        }
		avg /= n;
		for (int i = 0; i < n; i++) {
            if (ar[i] > avg) {
				cnt++;
			}
		}
		double percent = cnt / n * 100;
		cout << fixed;
		cout.precision(3);
		cout << percent << "%\n";
    }

    return 0;
}