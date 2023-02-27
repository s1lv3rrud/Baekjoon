import sys
input = sys.stdin.readline

n = int(input())

loss = list(map(int, input().split()))
loss.sort()

flag = 0
if n % 2 == 1:
    n -= 1
    flag = 1

max = 0
for i in range(int(n/2)):
    current = loss[i]+loss[n-i-1]
    if max < current:
        max = current

if flag == 1:
    if max < loss[n]:
        max = loss[n]
        
print(max)