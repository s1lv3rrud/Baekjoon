n = int(input())

num3 = 0
flag = 0

while n >= 0:
    if n%5==0 or n == 0:
        print(num3+int(n/5))
        flag = 1
        break
    else:
        num3 += 1
        n -= 3
if(flag == 0):
    print(-1)