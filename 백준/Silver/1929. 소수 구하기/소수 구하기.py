import math

m, n = map(int,input().split())

def solve(a):
    if a == 1:
        return False
    elif a == 2:
        return True
    else:
        for j in range(2, int(math.sqrt(a)) + 1):
            if a % j == 0:
                return False
        return True

for i in range(m, n+1):
    if solve(i) == True:
        print(i)