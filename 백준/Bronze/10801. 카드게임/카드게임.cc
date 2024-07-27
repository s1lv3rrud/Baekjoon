#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> a(10);
  vector<int> b(10);

  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < 10; i++) {
    cin >> b[i];
  }

  int a_score = 0, b_score = 0;
  for (int i = 0; i < 10; i++) {
    if (a[i] > b[i]) {
      a_score++;
    } else if (a[i] < b[i]) {
      b_score++;
    }
  }
  if(a_score > b_score) {
    cout << "A";
  } else if(a_score < b_score) {
    cout << "B";
  } else {
    cout << "D";
  }

  return 0;
}