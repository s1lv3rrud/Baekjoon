/*
main으로 시작해서 main으로 끝난다
div 사이에 하나의 문단이 존재
p 사이에 하나의 문장이 존재
p 사이에는 main, div, p 태그를 제외한 다른 태그 존재 가능
p 태그 파싱 방법
1. p 태그 안의 태그 지우기
2. 문장 시작과 끝의 공백 지우기
3. 문장에서 공백이 2개 이상 붙어있다면 하나의 공백으로 치환
4. p 태그 지우기
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);
  // main 태그 제거
  s = s.substr(6, s.size() - 13);

  for (int i = 0; i < s.size(); i++) {
    if (s.substr(i, 4) == "<div") {
      i += 4;
      while (s[i] != '"') {
        i++;
      }
      i++;
      string temp;
      while (s[i] != '"') {
        temp += s[i];
        i++;
      }
      cout << "title : " << temp << '\n';
    } else if (s.substr(i, 3) == "<p>") {
      i += 3;
      string temp;
      while (s.substr(i, 4) != "</p>") {
        temp += s[i];
        i++;
      }
      i += 3;

      // 태그 제거
      string result;
      bool isTag = false;
      for (auto t : temp) {
        if (t == '<') {
          isTag = true;
        } else if (t == '>') {
          isTag = false;
        } else if (!isTag) {
          result += t;
        }
      }

      // 문장 시작과 끝의 공백 제거
      while (result.size() > 0 && result.substr(0, 1) == " ") {
        result.erase(0, 1);
      }
      while (result.size() > 0 && result.substr(result.size() - 1, 1) == " ") {
        result.erase(result.size() - 1, 1);
      }

      // 공백이 2개 이상 붙어있다면 하나의 공백으로 치환

      if (result.size() > 0) {
        for (int j = 0; j < result.size(); j++) {
          if (result.substr(j, 1) == " ") {
            while (result.substr(j + 1, 1) == " ") {
              result.erase(j + 1, 1);
            }
          }
        }
      }

      cout << result << '\n';
    }
  }

  return 0;
}