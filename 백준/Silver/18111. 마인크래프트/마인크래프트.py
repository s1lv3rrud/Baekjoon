import sys

input = sys.stdin.readline

n, m, b = map(int, input().split())

ground = [list(map(int, input().split())) for i in range(n)]

maxheight = max(max(ground))
minheight = min(min(ground))

mintime = 128000000
height = 0

for h in range(maxheight, minheight - 1, -1):
    t_time = 0
    t_add = 0
    t_sub = 0
    for i in range(n):
        for j in range(m):
            if ground[i][j] > h:
                t_sub += ground[i][j]-h
            else: # else vs elif
                t_add += h-ground[i][j]
    
    if t_add <= b + t_sub:
        t_time = t_sub*2+t_add
        if t_time < mintime:
            mintime = t_time
            height = h

print(mintime, height)