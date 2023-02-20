import sys
input = sys.stdin.readline

n, m = map(int, input().split())

pokemonint = {}
pokemonname = {}

for i in range(n):
    name = input().rstrip()
    pokemonint[name] = i
    pokemonname[i] = name

for j in range(m):
    order = input().rstrip()
    if order.isdigit():
        print(pokemonname[int(order)-1])
    else:
        print(pokemonint[order] + 1)