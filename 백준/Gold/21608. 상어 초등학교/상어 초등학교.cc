#include <bits/stdc++.h>

using namespace std;

int n, stu, ans = 0;
int fav[410][4];
int board[30][30];
vector<tuple<int, int, int, int>> v(0); // x, y, 좋아하는 학생, 비어있는 칸
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool isIn(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	int aX, aY, aFav, aEmpty;
	int bX, bY, bFav, bEmpty;
	tie(aX, aY, aFav, aEmpty) = a;
	tie(bX, bY, bFav, bEmpty) = b;
    if (aFav == bFav) {
		if (aEmpty == bEmpty) {
            if (aX == bX) {
				return aY < bY;
			}
			return aX < bX;
		}
		return aEmpty > bEmpty;
    }
	return aFav > bFav;
}

int main(int argc, char** argv) {
    cin >> n;

    for (int i = 0; i < n * n; i++) {
        cin >> stu;
		for (int j = 0; j < 4; j++) {
			cin >> fav[stu][j];
		}
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < n; r++) {
				if(board[c][r] != 0) continue;
				int favCnt = 0, emptyCnt = 0, nc, nr;
                for (int d = 0; d < 4; d++){
					nc = c + dx[d], nr = r + dy[d];
					if (!isIn(nc, nr)) continue;
					if (board[nc][nr] == 0) {
						emptyCnt++;
					}
					else {
						for (int f = 0; f < 4; f++) {
						    if (board[nc][nr] == fav[stu][f]) {
						        favCnt++;
							}
						}
					}
                }
				v.push_back({ c, r, favCnt, emptyCnt });
            }
        }

        sort(v.begin(), v.end(), cmp);
		int _x, _y, _fav, _empty;
		tie(_x, _y, _fav, _empty) = v[0];
		board[_x][_y] = stu;
        v.clear();
    }

	for (int c = 0; c < n; c++) {
		for (int r = 0; r < n; r++) {
			int cnt = 0, stu = board[c][r];
			for (int d = 0; d < 4; d++) {
				int nc = c + dx[d], nr = r + dy[d];
				if (!isIn(nc, nr)) continue;
				for (int f = 0; f < 4; f++) {
					if (board[nc][nr] == fav[stu][f]) {
						cnt++;
					}
				}
			}
			if (cnt == 1) {
				ans += 1;
			}
			else if (cnt == 2) {
				ans += 10;
			}
			else if (cnt == 3) {
				ans += 100;
			}
			else if (cnt == 4) {
				ans += 1000;
			}
		}
	}

	cout << ans;

    return 0;
}