from collections import deque

import sys
input = sys.stdin.readline

n = int(input())
plain = []

for i in range(n):
    [x, y] = map(int, input().split())
    plain.append([x, y])

sortedplain = sorted(plain)


for i in range(n):
    print(sortedplain[i][0], sortedplain[i][1])
