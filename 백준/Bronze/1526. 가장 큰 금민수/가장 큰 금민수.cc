#include <bits/stdc++.h>

using namespace std;

bool isGold(int n){
  while(n){
    if(n % 10 != 7 && n % 10 != 4){
      return false;
    }
    n /= 10;
  }
  return true;
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  n++;
  while(n--){
    if(isGold(n)){
      cout << n << endl;
      break;
    }
  }

  return 0;
}