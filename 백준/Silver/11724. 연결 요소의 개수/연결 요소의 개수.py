import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visit = [0 for _ in range(n+1)]
count = 0

def dfs(i):
    for g in graph[i]:
        if visit[g] == 0:
            visit[g] = 1
            dfs(g)

for i in range(1, n+1):
    if visit[i] == 0:
        if graph[i]:
            dfs(i)
            count += 1
        else:
            count += 1
            visit[i] = 1

print(count)