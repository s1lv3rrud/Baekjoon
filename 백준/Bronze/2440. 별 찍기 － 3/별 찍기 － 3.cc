#include <bits/stdc++.h>

using namespace std;

int k, q, l, v, n, p;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}

		cout << "\n";
	}
    return 0;
}