import sys
input = sys.stdin.readline

n = int(input())

time = list(map(int, input().split()))

time.sort()

totaltime = [0 for _ in range(n)]
for i in range(n):
    totaltime[i] = 0
    for j in range(i+1):
        totaltime[i] += time[j]

print(sum(totaltime))