import sys
input = sys.stdin.readline

t = int(input())

num = [0, 1, 2, 4]

for i in range(4, 11):
    num.append(num[i-1]+num[i-2]+num[i-3])

for i in range(t):
    n = int(input())
    print(num[n])