import sys
input = sys.stdin.readline

n = int(input())

price = [int(input()) for _ in range(n)]

price.sort(reverse = True)

total = sum(price)
for i in range(2, n, 3):
    total -= price[i]

print(total)

