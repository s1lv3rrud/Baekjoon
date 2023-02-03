n = int(input())

for i in range(1, n+1):
    total = i + sum(map(int, str(i))) 
    if total == n:
        print(i)
        break
    elif i == n:
        print(0)