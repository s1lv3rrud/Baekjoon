#include <bits/stdc++.h>

using namespace std;

int answer = 1;

void dfs(int curNode, int sheep, int wolf, vector<int> nextNode, vector<int> info, vector<vector<int>> v) {
    int animal = info[curNode];
    if (animal == 0) sheep++;
    else wolf++;

    answer = max(answer, sheep);

    if (wolf >= sheep) return;

    for (int i = 0; i < nextNode.size(); i++) {
        vector<int> next = nextNode;
        // 이번에 방문한 노드 삭제
        next.erase(next.begin() + i);
        // 이번에 방문한 노드의 다음 노드들 추가
        for (int j = 0; j < v[nextNode[i]].size(); j++) {
            next.push_back(v[nextNode[i]][j]);
        }
        dfs(nextNode[i], sheep, wolf, next, info, v);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    // edges 분류
    vector<vector<int>> v(info.size());

    for (int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
    }

    // 초기화
    vector<int> nextNode;
    for (int i = 0; i < v[0].size(); i++) {
        nextNode.push_back(v[0][i]);
    }

    dfs(0, 0, 0, nextNode, info, v);

    return answer;
}