import sys
input = sys.stdin.readline

def solve(n):
    num = 666
    count = 1
    while count <= n:
        if '666' in str(num):
            count += 1
        num += 1

    return num-1

n = int(input())

print(solve(n))
