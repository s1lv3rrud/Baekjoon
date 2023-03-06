import sys
input = sys.stdin.readline

n = int(input())

sqrt = [-1] * (n+1)
sqrt[0], sqrt[1] = 0, 1
for i in range(2, n+1):
    minnum = i
    j = 1
    while j*j <= i:
        minnum = min(minnum, sqrt[i-j*j])
        j += 1
    sqrt[i] = minnum + 1

print(sqrt[n])