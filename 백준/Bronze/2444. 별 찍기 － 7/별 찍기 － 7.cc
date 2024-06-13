#include <bits/stdc++.h>

using namespace std;

int n;

void printStar(int s) {
	for (int i = 0; i < n - s; i++) {
		cout << " ";
	}
	for (int i = 0; i < s * 2 - 1; i++) {
		cout << "*";
	}
	cout << endl;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++) {
		printStar(i);
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		cout << "*";
	}
	cout << endl;
	for (int i = n - 1; i > 0; i--) {
		printStar(i);
	}

    return 0;
}