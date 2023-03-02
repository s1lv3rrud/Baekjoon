import sys
input = sys.stdin.readline

def solve(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return solve(n-2)+solve(n-1)

n = int(input())
print(solve(n))