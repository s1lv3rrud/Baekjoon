import sys
import math
input = sys.stdin.readline

n = int(input())

str = input()

r = 31
M = 1234567891
sum = 0
for i in range(n):
    sum += (ord(str[i])-96)*math.pow(r, i)

print(int(sum%M))