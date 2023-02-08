import sys

input = sys.stdin.readline

n = int(input())

people = []
rank = []

for i in range(n):
    cm, kg = map(int, input().split())
    people.append([cm, kg])

for i in range(n):
    this_rank = 0
    for j in range(n):
        if (people[i][0] < people[j][0]) & (people[i][1] < people[j][1]):
            this_rank += 1
    rank.append(this_rank + 1)

for i in range(n):
    print(rank[i], end = " ")