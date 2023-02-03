import itertools

n, m = map(int, input().split())

num = []

num = list(map(int, input().split()))

nCr = itertools.combinations(num, 3)

sum = 0
sub = m
winsum = 0

for i in nCr:
    for j in range(3):
        sum += i[j]
    if(sum <= m):
        if(m-sum < sub):
            winsum = sum
            sub = m-sum
    sum = 0

print(winsum)