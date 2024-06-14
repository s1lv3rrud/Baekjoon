#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	int h, w, height;
	cin >> h >> w;
	int ar[500][500];
	for (int i = 0; i < w; i++) {
		cin >> height;
		for (int j = 0; j < h - height; j++) {
			ar[j][i] = 0;
		}
		for (int j = h - height; j < h; j++) {
			ar[j][i] = 1;
		}
	}

	int rain = 0;
	for (int i = 0; i < h; i++) {
		int prev = -1;
		for (int j = 0; j < w; j++) {
			if (ar[i][j] == 1) {
				if (prev != -1) {
					for (int p = prev + 1; p < j; p++) {
						if (ar[i][p] == 0) {
							rain++;
						}
				    }
				}
				prev = j;
			}
		}
	}

	cout << rain;

    return 0;
}