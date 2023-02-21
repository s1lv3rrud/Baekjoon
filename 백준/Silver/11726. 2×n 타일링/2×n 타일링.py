import math
import sys
input = sys.stdin.readline

n = int(input())

method = [0, 1, 2]
for i in range(3, n+1):
    method.append((method[i-1]+method[i-2])%10007)
    
print(method[n])