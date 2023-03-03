import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
pairs = int(input())

graph = [[] for _ in range(n+1)]
for _ in range(pairs):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visit = [0] * (n+1)
visit[1] = 1
dq = deque([1])
while dq:
    current = dq.popleft()
    for next in graph[current]:
        if visit[next] == 0:
            dq.append(next)
            visit[next] = 1
        
print(sum(visit)-1)
