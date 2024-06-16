#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> nodes[10001];
bool visited[10001];
int farthestNode, farthestDist;

void dfs(int node, int depth) {
	if (visited[node]) return;

	visited[node] = true;
	
	if (depth > farthestDist) {
		farthestNode = node;
		farthestDist = depth;
	}

	for (auto next : nodes[node]) {
		dfs(next.first, depth + next.second);
	}
}

int main(int argc, char** argv) {
	cin >> n;
	int parent, child, weight;
	for (int i = 0; i < n - 1; i++) {
		cin >> parent >> child >> weight;
		nodes[parent].push_back({ child, weight });
		nodes[child].push_back({ parent, weight });
	}

	// 루트 노드로부터 가장 먼 점 구하기
	dfs(1, 0);

	farthestDist = 0;
	memset(visited, false, sizeof(visited));

	// 가장 먼 점으로부터 가장 먼 점 구하기
	dfs(farthestNode, 0);
	cout << farthestDist;

    return 0;
}