#include <bits/stdc++.h>

using namespace std;

int a, b;

bool isSosu(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalin(int n) {
	string s = to_string(n);
	string s1 = s;
	string s2 = s;
	reverse(s2.begin(), s2.end());

	if (s1 != s2) return false;
	return true;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	for (int i = a; i <= 10000000; i++) {
		if (i > b) break;
		if (isPalin(i) && isSosu(i)) cout << i << '\n';
	}
	cout << -1;
	
	return 0;
}