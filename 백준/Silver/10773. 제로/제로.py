import sys
input = sys.stdin.readline

import math

k = int(input())

stack = []
for i in range(k):
    a = int(input())
    if a == 0:
        stack.pop()
    else:
        stack.append(a)

print(sum(stack))