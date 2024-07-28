#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  if(s.size() < 5){
    cout << "not cute";
    return 0;
  }

  if(s.substr(s.size() - 5, 5) == "driip"){
    cout << "cute";
  }
  else{
    cout << "not cute";
  }

  return 0;
}