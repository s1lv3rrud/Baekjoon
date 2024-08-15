/*

 */

#include <bits/stdc++.h>
using namespace std;

string subTime(string t1, string t2) {
  int h1 = stoi(t1.substr(0, 2));
  int m1 = stoi(t1.substr(3, 2));
  int h2 = stoi(t2.substr(0, 2));
  int m2 = stoi(t2.substr(3, 2));

  int h = h2 - h1;
  int m = m2 - m1;

  if (m < 0) {
    m += 60;
    h--;
  }

  string res = "";
  if (h < 10) res += "0";
  res += to_string(h) + ":";
  if (m < 10) res += "0";
  res += to_string(m);

  return res;
}

string addTime(string t1, string t2) {
  int h1 = stoi(t1.substr(0, 2));
  int m1 = stoi(t1.substr(3, 2));
  int h2 = stoi(t2.substr(0, 2));
  int m2 = stoi(t2.substr(3, 2));

  int h = h2 + h1;
  int m = m2 + m1;

  if (m >= 60) {
    m -= 60;
    h++;
  }

  string res = "";
  if (h < 10) res += "0";
  res += to_string(h) + ":";
  if (m < 10) res += "0";
  res += to_string(m);

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, string>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  int team1Score = 0, team2Score = 0, curWinning = 0;
  string prevTime, team1Time = "00:00", team2Time = "00:00", time;
  for (auto a : v) {
    if (curWinning != 0) {
      time = subTime(prevTime, a.second);
      if (curWinning == 1) {
        team1Time = addTime(team1Time, time);
      } else {
        team2Time = addTime(team2Time, time);
      }
    }

    if (a.first == 1)
      team1Score++;
    else
      team2Score++;

    if (team1Score > team2Score)
      curWinning = 1;
    else if (team2Score > team1Score)
      curWinning = 2;
    else
      curWinning = 0;

    prevTime = a.second;
  }
  if (curWinning != 0) {
    time = subTime(prevTime, "48:00");
    if (curWinning == 1) {
      team1Time = addTime(team1Time, time);
    } else {
      team2Time = addTime(team2Time, time);
    }
  }

  cout << team1Time << "\n" << team2Time;

  return 0;
}