/*
14500 테트로미노
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> v(500, vector<int>(500));
vector<vector<pair<int, int>>> tetr(19, vector<pair<int, int>>(4));

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  tetr[0] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};  // -
  tetr[1] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};  // |
  tetr[2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};  // ㅁ
  tetr[3] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};  // ㄱ
  tetr[4] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}};
  tetr[5] = {{0, 0}, {0, 1}, {0, 2}, {1, 2}};  // ㄱ
  tetr[6] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};  // ㄴ
  tetr[7] = {{0, 2}, {1, 0}, {1, 1}, {1, 2}};
  tetr[8] = {{0, 0}, {1, 0}, {1, 1}, {2, 0}};  // ㅏ
  tetr[9] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}};
  tetr[10] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}};
  tetr[11] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
  tetr[12] = {{0, 1}, {1, 0}, {1, 1}, {2, 1}};  // ㅓ
  tetr[13] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
  tetr[14] = {{0, 0}, {0, 1}, {0, 2}, {1, 1}};  // ㅜ
  tetr[15] = {{0, 0}, {0, 1}, {1, 0}, {2, 0}};
  tetr[16] = {{0, 1}, {1, 1}, {2, 0}, {2, 1}};
  tetr[17] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};  // ㄴ
  tetr[18] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}};  // ㅗ

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (auto t : tetr) {
        int sum = 0;
        for (int k = 0; k < 4; k++) {
          int x = i + t[k].first;
          int y = j + t[k].second;
          if (x < 0 || x >= n || y < 0 || y >= m) {
            sum = 0;
            break;
          }
          sum += v[x][y];
        }
        ans = max(ans, sum);
      }
    }
  }

  cout << ans;

  return 0;
}