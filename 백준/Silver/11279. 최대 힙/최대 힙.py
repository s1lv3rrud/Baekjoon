import sys
input = sys.stdin.readline

import heapq

n = int(input())

maxheap = []

for _ in range(n):
    num = int(input())
    if num == 0:
        try:
            result = heapq.heappop(maxheap)
            print(result-result-result)
        except:
            print(0)
    else:
        num -= num + num
        heapq.heappush(maxheap, num)
