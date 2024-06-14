#include <bits/stdc++.h>

using namespace std;
string s;
bool visited[100];

void solve(int start, int end) {
	if (start == end) return;
	char c = s[start];
	int idx = start;
	for (int i = start + 1; i < end; i++) {
		if (s[i] < c) {
			c = s[i];
			idx = i;
		}
	}
	visited[idx] = true;
	for (int i = 0; i < s.size(); i++) {
		if (visited[i]) cout << s[i];
	}
	cout << endl;
	solve(idx + 1, end);
	solve(start, idx);
}

int main(int argc, char** argv) {
	cin >> s;
	
	solve(0, s.size());

    return 0;
}