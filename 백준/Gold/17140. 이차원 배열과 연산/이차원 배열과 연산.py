def sort(A, func):  # 정렬
    newA = []
    for row in A:
        countNum, newRow = [], []
        for num in set(row):
            if num == 0:
                continue
            count = row.count(num)
            countNum.append((num, count))
        countNum = sorted(countNum, key=lambda x: (x[1], x[0]))
        for num, count in countNum:
            newRow += [num, count]
        newA.append(newRow)

    maxRowLen = max(len(row) for row in newA)
    for row in newA:
        if len(row) < maxRowLen:
            row[len(row):maxRowLen] = [0]*(maxRowLen-len(row))
        if len(row) > 100:
            row = row[:100]

    if func == 'R':
        return newA
    elif func == 'C':
        return list(zip(*newA))


r, c, k = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(3)]

time = 0
while (time <= 100):
    maxRowLen = max(len(row) for row in A)
    # A의 범위를 넘어가는 경우 A[r-1][c-1] == k인지 확인하지 않는다
    if 0 <= r-1 < len(A) and 0 <= c-1 < maxRowLen and A[r-1][c-1] == k:
        break

    if len(A) >= maxRowLen:
        A = sort(A, 'R')
    else:
        A = sort(list(zip(*A)), 'C')
    time += 1

if (time > 100):
    time = -1
print(time)
