import sys
input = sys.stdin.readline

n = int(input())

number = [0]*10001

for i in range(n):
    num = int(input())
    number[num] += 1

for i in range(10001):
    if number[i] != 0:
        for j in range(number[i]):
            print(i)