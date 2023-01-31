n = int(input())

for i in range(n):
    floor = int(input())
    ho = int(input())
    p = [h for h in range(1, ho+1)] # 0층 초기화
    for j in range(floor):
        for k in range(1, ho):
            p[k] += p[k-1]

    print(p[-1])