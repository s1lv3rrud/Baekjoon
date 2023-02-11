import sys
from collections import Counter
input = sys.stdin.readline

n,m,b = map(int,input().split())
ground = []
for i in range(n):
    ground += list(map(int,input().split()))
sumground = sum(ground)
ground = Counter(ground)
mintime = 256 * 500 * 500 * 3 * 2
minheight = 256

for h in range(max(ground), min(ground)-1, -1):
    t_time = 0
    t_block = (h * n * m) - (sumground + b) # 필요한 블럭
    if t_block <= 0:
        for height, count in ground.items():
            if height < h:
                t_time += (h - height) * count
            elif height >  h:
                t_time += (height - h) * 2 * count
        if t_time < mintime:
            minheight = h
            mintime = t_time

print(mintime,minheight)