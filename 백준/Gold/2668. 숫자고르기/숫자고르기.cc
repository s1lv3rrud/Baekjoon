#include <bits/stdc++.h>

using namespace std;

int n;
int secondRow[101];
int visited[101];
vector<int> ans;

void dfs(int cur, int start) {
	// 처음으로 돌아왔다면
	if (visited[cur]) {
		if (cur == start) {
			ans.push_back(cur);
		}
		return;
	}
	visited[cur] = 1;
	dfs(secondRow[cur], start);
}

int main(int argc, char** argv) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> secondRow[i];
	
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto a : ans) cout << a << endl;

    return 0;
}