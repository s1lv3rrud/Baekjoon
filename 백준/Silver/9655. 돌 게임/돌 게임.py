import sys

input = sys.stdin.readline

n = int(input())

n = n % 2

if(n == 1):
    print("SK")
else:
    print("CY")