from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
dq = deque([i for i in range(1, n+1)])
for i in range(n-1):
    dq.popleft()
    dq.append(dq.popleft())

print(dq.pop())