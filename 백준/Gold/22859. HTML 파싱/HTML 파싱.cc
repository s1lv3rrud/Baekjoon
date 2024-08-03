#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    // main 태그 제거
    s = s.substr(6, s.size() - 13);

    for (size_t i = 0; i < s.size(); i++) {
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
            i += 3;  // </p>를 건너뛰기 위해

            // 태그 제거
            string result;
            bool insideTag = false;
            for (char c : temp) {
                if (c == '<') insideTag = true;
                else if (c == '>') insideTag = false;
                else if (!insideTag) result += c;
            }

            // 문장 시작과 끝의 공백 제거
            result = regex_replace(result, regex("^ +| +$|( ) +"), "$1");

            cout << result << '\n';
        }
    }

    return 0;
}