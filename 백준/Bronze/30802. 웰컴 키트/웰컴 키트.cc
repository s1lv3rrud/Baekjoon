/*
 */

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int size[6];
  for (int i = 0; i < 6; i++) {
    cin >> size[i];
  }

  int t, p;
  cin >> t >> p;

  int tshirt = 0, pendummy = 0, pen = 0;

  for (double s : size) {
    tshirt += ceil(s / t);
  }
  pendummy = int(n / p);
  pen = n % p;

  cout << tshirt << "\n";
  cout << pendummy << " " << pen << "\n";

  return 0;
}
