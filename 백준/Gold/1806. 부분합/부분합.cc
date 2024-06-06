#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s;

	cin >> n >> s;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int start = 0, end = 0, sum = 0, ans = INT_MAX;

	while (start <= end) {
		if (sum >= s) {
			ans = min(ans, end - start);
			sum -= v[start++];
		}
		else if (end == n) break;
		else sum += v[end++];
	}

	if (ans == INT_MAX) cout << 0;
	else cout << ans;
	
	return 0;
}