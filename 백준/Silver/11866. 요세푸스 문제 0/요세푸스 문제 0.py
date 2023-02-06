from collections import deque

n, k = map(int, input().split())
dq = deque([i for i in range(1, n+1)])

print("<", end = '')
while len(dq) != 0:
    for i in range(k-1):
        dq.append(dq.popleft())
    if len(dq) != 1:
        print(dq.popleft(), end = ', ')
    else:
        print(dq.popleft(), end = '>')