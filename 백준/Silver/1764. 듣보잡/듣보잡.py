import sys
input = sys.stdin.readline

n, m = map(int, input().split())

deut = set(input() for _ in range(n))
bo = set(input() for _ in range(m))

deutbo = sorted(list(deut&bo))

print(len(deutbo))
for i in deutbo:
    print(i, end='')