#include <bits/stdc++.h>

using namespace std;

int n, m, s, e;
int ar[2002];
int dp[2002][2002];

void solve() {
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;
		if (ar[i] == ar[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			if (ar[j] == ar[j + i] && dp[j + 1][j + i - 1] == 1) dp[j][j + i] = 1;
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	solve();

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		if (dp[s][e] == 1) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	
	return 0;
}