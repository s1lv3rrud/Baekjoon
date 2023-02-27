from sys import stdin

k = int(stdin.readline())
dist = list(map(int, stdin.readline().split()))
cost = list(map(int, stdin.readline().split()))
res = 0

c = cost[0]
for i in range(k - 1):
    if c > cost[i]:
        c = cost[i]
    res += c * dist[i]

print(res)