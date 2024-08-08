/*

 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, newScore, p;
  cin >> n >> newScore >> p;

  if (n == 0) {
    cout << 1;
    return 0;
  }

  vector<int> scores(n+1);
  for (int i = 0; i < n; i++) {
    cin >> scores[i];
  }

  scores[n] = newScore;

  sort(scores.begin(), scores.end(), greater<int>());

  int rank = 0, tempRank = 0;
  bool flag = false;
  for(int i = 0;i<n+1;i++){
    if(scores[i] == newScore){
      if(!flag)rank = i+1;
      flag = true;
      tempRank = i+1;
    }
  }

  if(tempRank > p){
    cout << -1;
  }
  else if(rank <= p){
    cout << rank;
  }
  

  return 0;
}