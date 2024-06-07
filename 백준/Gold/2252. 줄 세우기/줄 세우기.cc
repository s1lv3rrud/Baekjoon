#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> cnt(n + 1);
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		cnt[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++)
		{
			cnt[graph[cur][i]]--;
			if (cnt[graph[cur][i]] == 0)
			{
				q.push(graph[cur][i]);
			}
		}
	}

	return 0;
}