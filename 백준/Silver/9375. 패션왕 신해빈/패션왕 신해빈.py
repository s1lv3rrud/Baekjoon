from itertools import combinations
import sys
input = sys.stdin.readline

test = int(input())

for t in range(test):
    clothes = {}
    n = int(input())
    for _ in range(n):
        cloth = input().split()
        if cloth[1] in clothes:
            clothes[cloth[1]].append(cloth[0])
        else:
            clothes[cloth[1]] = [cloth[0]]
    clothnum = [len(clothes[c]) for c in clothes]
    num = 1
    for i in range(len(clothnum)):
        num *= clothnum[i]+1

    print(num-1)

    