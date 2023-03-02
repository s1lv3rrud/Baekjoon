import sys
input = sys.stdin.readline

fibo = [-1 for _ in range(91)]
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