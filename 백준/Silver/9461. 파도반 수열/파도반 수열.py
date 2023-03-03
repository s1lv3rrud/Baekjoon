import sys
input = sys.stdin.readline

n = int(input())

P = [0 for _ in range(101)]
P[1] = 1
P[2] = 1
P[3] = 1
for i in range(4, 101):
    P[i] = P[i-2]+P[i-3]

for _ in range(n):
    test = int(input())
    print(P[test])