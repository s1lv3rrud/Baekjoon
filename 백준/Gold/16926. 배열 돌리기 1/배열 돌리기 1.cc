#include <bits/stdc++.h>

using namespace std;

int n, m, r;
int ar[310][310];

int main(int argc, char** argv) {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	int depth = min(n, m) / 2;

	while (r--) {
		for (int i = 0; i < depth; i++) {
			int x = i, y = i;
			int temp = ar[x][y];
			for (int j = i; j < m - i - 1; j++) {
				ar[x][y] = ar[x][y + 1];
				y++;
			}
			for (int j = i; j < n - i - 1; j++) {
				ar[x][y] = ar[x + 1][y];
				x++;
			}
			for (int j = i; j < m - i - 1; j++) {
				ar[x][y] = ar[x][y - 1];
				y--;
			}
			for (int j = i; j < n - i - 1; j++) {
				ar[x][y] = ar[x - 1][y];
				x--;
			}
			ar[x + 1][y] = temp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}