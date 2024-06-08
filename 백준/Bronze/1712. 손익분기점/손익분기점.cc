#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, cnt;
	cin >> a >> b >> c;

	if (b >= c) cnt = -1;
	else cnt = a / (c - b) + 1;

	cout << cnt;

	return 0;
}