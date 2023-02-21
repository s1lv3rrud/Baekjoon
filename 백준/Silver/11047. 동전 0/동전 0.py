import sys
input = sys.stdin.readline

n, k = map(int, input().split())

value = [int(input()) for _ in range(n)]
value.reverse()

num = 0
for v in value:
    if v <= k:
        num += int(k / v)
        k = k % v

print(num)
