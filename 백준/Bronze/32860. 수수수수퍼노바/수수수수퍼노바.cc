#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  string code;
  if (M <= 26) {
    // A~Z
    code.push_back('A' + (M - 1));
  } else {
    // aa, ab, ac ... zz
    int x = M - 27;
    char first = 'a' + (x / 26);
    char second = 'a' + (x % 26);
    code.push_back(first);
    code.push_back(second);
  }

  cout << "SN " << N << code << "\n";

  return 0;
}
