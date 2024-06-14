#include <bits/stdc++.h>

using namespace std;

string s;
int minAns = INT_MAX, maxAns = 0;

void solve(vector<int> v, int cnt) {
	// 1. 홀수 개수 세기
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 1) {
			cnt++;
		}
	}
	switch (v.size()) {
	case 1:
		minAns = minAns < cnt ? minAns : cnt;
		maxAns = maxAns > cnt ? maxAns : cnt;
		break;
	case 2:
		v[0] += v[1];
		v.pop_back();
		if (v[0] >= 10) {
			v.push_back(v[0] / 10);
			v[0] %= 10;
		}
		solve(v, cnt);
		break;
	default:
		for (int first = 1; first < v.size() - 1; first++) {
			for (int second = first + 1; second < v.size(); second++) {
				int a = 0, b = 0, c = 0;
				for (int i = 0; i < first; i++) {
					a += v[i] * pow(10, first - i - 1);
				}
				for (int i = first; i < second; i++) {
					b += v[i] * pow(10, second - i - 1);
				}
				for (int i = second; i < v.size(); i++) {
					c += v[i] * pow(10, v.size() - i - 1);
				}
				int newN = a + b + c;
				vector<int> newV;
				s = to_string(newN);
				for (int i = 0; i < s.size(); i++) {
					newV.push_back(s[i] - '0');
				}
				solve(newV, cnt);
			}
		}
		break;
	}
}

int main(int argc, char** argv) {
	cin >> s;

	vector<int> v;
	
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
	}

	solve(v, 0);
	
	cout << minAns << " " << maxAns << endl;

    return 0;
}