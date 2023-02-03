t = int(input())

for i in range(t):
    h, w, n = map(int, input().split())
    floor = int(n%h)
    ho = int(n/h)+1
    if floor == 0:
        floor = h
        ho = ho-1

    print(floor*100+ho)
