import sys
input = sys.stdin.readline

n, m = map(int, input().split())

pw = {}
for i in range(n):
    save = input().split()
    pw[save[0]] = save[1]

for i in range(m):
    site = input().rstrip()
    print(pw[site])