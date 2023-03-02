import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

fibo = [-1 for _ in range(10001)]
fibo[0] = 0
fibo[1] = 1

def solve(n):
    if fibo[n] > -1:
        return fibo[n]
    else:
        fibo[n] = solve(n-1) + solve(n-2)
    
    return fibo[n]

n = int(input())
print(solve(n))