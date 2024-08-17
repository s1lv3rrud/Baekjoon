/*
 */

#include <bits/stdc++.h>

using namespace std;

int n, insIdx;
vector<int> v, idx, lis, ans;

int binarySearch(int a) {
  int start = 0, end = lis.size() - 1, mid;

  while (start < end) {
    mid = (start + end) / 2;
    if (lis[mid] < a) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return end;
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  lis.push_back(v[0]);
  idx.push_back(0);
  for (int i = 1; i < n; i++) {
    if (v[i] > lis.back()) {
      lis.push_back(v[i]);
      idx.push_back(lis.size() - 1);
    } else {
      insIdx = binarySearch(v[i]);
      lis[insIdx] = v[i];
      idx.push_back(insIdx);
    }
  }

  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << "(" << idx[i] << ") ";
  // }
  // cout << "\n";

  // ans에 최종 LIS 저장
  int findIdx = lis.size() - 1;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (findIdx == idx[i]) {
      ans.push_back(v[i]);
      findIdx--;
    }
  }

  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }

  return 0;
}