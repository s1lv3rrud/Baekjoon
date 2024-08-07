/*

 */

#include <bits/stdc++.h>
using namespace std;

bool selection_sort(vector<int>& a, vector<int>& b) {
  for(int last = a.size() - 1; last > 0; last--) {
    int max_index = 0;
    for(int i = 0; i <= last; i++) {
      if(a[i] > a[max_index]) {
        max_index = i;
      }
    }
    swap(a[max_index], a[last]);
    if(a == b) {
      return true;
    }
  }
  return false;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  if(a==b) cout << 1;
  else cout << selection_sort(a, b);

  return 0;
}