import sys
input = sys.stdin.readline

import math

n = int(input())

# 1개
if int(math.sqrt(n)) ** 2 == n:
    print(1)
    exit()

# 2개
for i in range(int(math.sqrt(n)), int(math.sqrt(n//2))-1, -1):
    if int(math.sqrt(n-i*i)) ** 2 == n-i*i:
        print(2)
        exit()

# 3개
for i in range(int(math.sqrt(n)), int(math.sqrt(n//3))-1, -1):
    for j in range(int(math.sqrt(n-i*i)), int(math.sqrt((n-i*i)//3))-1, -1):
        if int(math.sqrt(n-i*i-j*j)) ** 2 == n-i*i-j*j:
            print(3)
            exit()

# 4개
print(4)

