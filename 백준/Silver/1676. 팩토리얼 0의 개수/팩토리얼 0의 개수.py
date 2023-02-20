import sys
input = sys.stdin.readline

n = int(input())

num = 0
for i in range(1, n+1):
    if i % 5 == 0:
        num += 1
    if i % 25 == 0:
       num += 1
    if i % 125 == 0:
        num += 1 
    
print(num)