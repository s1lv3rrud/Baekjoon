#include <bits/stdc++.h>

using namespace std;

int n;
string s;
bool dp[2510][2510];
int dp2[2510];

void solve() {
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;
		if (s[i] == s[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			if (s[j] == s[j + i] && dp[j + 1][j + i - 1] == 1) dp[j][j + i] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		dp2[i] = INT_MAX;
		for (int j = 1; j <= i; j++)
		{
			if (dp[j][i]) dp2[i] = min(dp2[i], dp2[j - 1] + 1);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	s = " " + s;

	solve();

	cout << dp2[n];
	
	return 0;
}