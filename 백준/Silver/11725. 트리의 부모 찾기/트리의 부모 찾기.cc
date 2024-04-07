#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> graph[100001];
bool visited[100001];
int parent[100001];
queue<int> q;

void BFS() {
    while (!q.empty()) {
        int p = q.front();
        q.pop();

        for (int i = 0; i < graph[p].size(); i++) {
            int child = graph[p][i];
            if (!visited[child]) {
                parent[child] = p;
                visited[child] = true;
                q.push(child);
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    q.push(1);
    visited[1] = true;
    BFS();

    for (int i = 2; i < n + 1; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}