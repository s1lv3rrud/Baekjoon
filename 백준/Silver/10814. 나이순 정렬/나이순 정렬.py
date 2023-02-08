import sys

input = sys.stdin.readline

n = int(input())

member = []

for i in range(n):
    age, name = input().split()
    age = int(age)
    member.append([age, i, name])

member = sorted(member)

for i in range(n):
    print(member[i][0], member[i][2])