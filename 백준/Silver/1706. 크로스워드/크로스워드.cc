#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> v(r, vector<int>(c));
  vector<string> words;
  for (int i = 0; i < r; i++) {
    string s, word = "";
    cin >> s;
    for (int j = 0; j < c; j++) {
      v[i][j] = s[j];
      if (s[j] == '#') {
        if (word != "") {
          if (word.size() != 1) words.push_back(word);
          word = "";
        }
      } else {
        word += s[j];
      }
    }
    if (word != "") {
      if (word.size() != 1) words.push_back(word);
    }
  }

  for (int j = 0; j < c; j++) {
    string word = "";
    for (int i = 0; i < r; i++) {
      if (v[i][j] == '#') {
        if (word != "") {
          if (word.size() != 1) words.push_back(word);
          word = "";
        }
      } else {
        word += v[i][j];
      }
    }
    if (word != "") {
      if (word.size() != 1) words.push_back(word);
    }
  }

  sort(words.begin(), words.end());

  cout << words[0] << endl;

  return 0;
}