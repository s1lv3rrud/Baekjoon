import sys, math
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    n, m = map(int, input().split())
    print(math.factorial(m)//(math.factorial(m-n)*math.factorial(n))) # mCn