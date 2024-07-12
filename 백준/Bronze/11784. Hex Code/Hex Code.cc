#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    while (getline(std::cin, s)) {
		string trans;
		for(int i = 0;i<s.size();i+=2){
			char cur = stoi(s.substr(i, 2), nullptr, 16);
			trans += cur;
		}
		cout << trans << endl;
    }

    return 0;
}