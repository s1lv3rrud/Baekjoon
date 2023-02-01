n = int(input())
num = 0
a = list(map(int, input().split()))
for b in a:
    flag = 0
    if b == 2:
        num += 1
    elif b == 1:
        continue
    else:
        for j in range(2, b):
            if b % j == 0:
                flag = 1
                break
        if flag == 0:
            num += 1
print(num)