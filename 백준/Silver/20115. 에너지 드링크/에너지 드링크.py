import sys
input = sys.stdin.readline

n = int(input())

energy = list(map(int, input().split()))

energy.sort(reverse = True)

amount = energy[0]

for e in energy[1:]:
    amount += e / 2

if amount % 1 == 0:
    print(int(amount))
else:
    print(amount)