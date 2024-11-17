#include <bits/stdc++.h>

using namespace std;

int main() {
  char s[50];
  cin.getline(s, 50);
  int N;
  cin >> N;

  vector<vector<bool>> check(N, vector<bool>(N, false));
  vector<int> student(N, 0);
  int cnt = 0;

  for (int i = 0; i < N; ++i) {
    int M;
    cin >> M;

    vector<int> students(M);
    for (int j = 0; j < M; ++j) {
      cin >> students[j];
    }

    int B;
    cin >> B;

    if (B) {
      for (int s : students) {
        check[i][s - 1] = true;
      }
    } else {
      for (int j = 0; j < N; ++j) {
        check[i][j] = true;
      }
      for (int s : students) {
        check[i][s - 1] = false;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i != j) {
        if (check[j][i]) {
          student[i]++;
        }
      } else {
        if (!check[j][i]) {
          student[i]++;
        }
      }
    }
    if (student[i] == N) {
      cnt++;
    }
  }

  if (cnt == 0) {
    cout << "swi" << endl;
  } else {
    for (int i = 0; i < N; ++i) {
      if (student[i] == N) {
        cout << (i + 1) << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
