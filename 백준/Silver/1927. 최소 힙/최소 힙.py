import sys
input = sys.stdin.readline

import heapq

n = int(input())

minheap = []

for _ in range(n):
    num = int(input())
    if num == 0:
        try:
            print(heapq.heappop(minheap))
        except:
            print(0)
    else:
        heapq.heappush(minheap, num)
