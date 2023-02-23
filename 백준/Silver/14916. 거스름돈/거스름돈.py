import sys
input = sys.stdin.readline

n = int(input())
num5 = 0
num2 = 0

if n % 2 == 0:
    num2 += int(n / 2)
else:
    num5 += 1
    num2 += int((n-5) / 2)

while(num2 >= 5):
    num2 -= 5
    num5 += 2

if n == 1 | n == 3:
    print(-1)
else:
    print(num5+num2)
