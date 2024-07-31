#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second < b.second;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  map<int, int> mogimap;
  int e, x;
  for (int i = 0; i < n; i++) {
    cin >> e >> x;
    mogimap[e] += 1;
    mogimap[x] -= 1;
  }

  int maxmogi = 0, anse, ansx, curmogi = 0;
  bool flag = false;
  for (auto m : mogimap) {
    curmogi += m.second;
    if (curmogi > maxmogi) {
      maxmogi = curmogi;
      anse = m.first;
      flag = true;
    } else if (flag && curmogi < maxmogi) {
      ansx = m.first;
      flag = false;
    }
  }
  cout << maxmogi << "\n" << anse << " " << ansx;

  return 0;
}
