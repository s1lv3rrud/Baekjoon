#include <bits/stdc++.h>

using namespace std;
\
int board[5][5];
bool isChecked[5][5];

bool isBingo() {
	int cnt, bingo = 0;
	// 가로
	for (int i = 0; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (isChecked[i][j]) cnt++;
			else break;
		}
		if (cnt == 5) bingo++;
	}

	// 세로
	for (int i = 0; i < 5; i++) {
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (isChecked[j][i]) cnt++;
			else break;
		}
		if (cnt == 5) bingo++;
	}

	// 대각선
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (isChecked[i][i]) cnt++;
		else break;
	}
	if (cnt == 5) bingo++;
	
	// 역대각선
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (isChecked[i][4 - i]) cnt++;
		else break;
	}
	if (cnt == 5) bingo++;

	if(bingo >= 3) return true;
	return false;
}

int main(int argc, char** argv) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	int num;
	for (int f = 0; f < 25; f++) {
		cin >> num;
		// check num
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (num == board[i][j]) {
					isChecked[i][j] = true;
					break;
				}
			}
		}

		// check bingo
		if (isBingo()) {
			cout << f + 1 << endl;
			break;
		}
	}


    return 0;
}