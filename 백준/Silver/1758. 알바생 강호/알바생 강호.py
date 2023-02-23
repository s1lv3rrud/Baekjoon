import sys
input = sys.stdin.readline

n = int(input())

tip = [int(input()) for _ in range(n)]
tip.sort(reverse=True)

money = 0
for i in range(n):
    t = tip[i]-i
    if t > 0:
        money += t

print(money)