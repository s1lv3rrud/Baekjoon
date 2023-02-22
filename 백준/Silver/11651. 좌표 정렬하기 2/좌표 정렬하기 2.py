import sys
input = sys.stdin.readline

n = int(input())

plain = []

for i in range(n):
    x, y = map(int, input().split())
    plain.append([y, x])

plain.sort()

for y, x in plain:
    print(x, y)