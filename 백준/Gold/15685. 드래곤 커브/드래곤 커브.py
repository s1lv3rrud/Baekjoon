MAX = 100
dragonCurve = [[0 for j in range(MAX+1)] for i in range(MAX+1)]  # 100 * 100 평면


def generateZero(x, y, d, n):  # 0세대 생성
    # 0: 오른쪽, 1: 위, 2: 왼쪽, 3: 아래
    dragonCurve[y][x] = n
    if d == 0:
        dragonCurve[y][x+1] = n
        # 끝점(기준점) 반환
        return x+1, y
    elif d == 1:
        dragonCurve[y-1][x] = n
        return x, y-1
    elif d == 2:
        dragonCurve[y][x-1] = n
        return x-1, y
    elif d == 3:
        dragonCurve[y+1][x] = n
        return x, y+1

# 식: 시작점(x,y) 이전 세대 점(a,b)
# a < x, b ≤ y: x+(y-b), y-(x-a)
# a ≥ x, b < y: x+(y-b), y+(x-a)
# a > x, b ≥ y: x-(y-b), y+(x-a)
# a ≤ x, b > y: x-(y-b), y-(x-a)


def addRotatePoint(a, b, x, y):
    if a < x and b <= y:
        return x+y-b, y-x+a
    elif a >= x and b < y:
        return x+y-b, y+a-x
    elif a > x and b >= y:
        return x-b+y, y+a-x
    elif a <= x and b > y:
        return x-b+y, y-x+a


def generateG(x, y, d, g, n):  # g세대까지 생성
    endX, endY = generateZero(x, y, d, n)
    addedPoint = []
    nextEndPoint = (0, 0)

    for i in range(g):
        for a in range(MAX+1):
            for b in range(MAX+1):
                if dragonCurve[b][a] == n:  # and (a != endX or b != endY):
                    point = addRotatePoint(a, b, endX, endY)
                    if point:
                        addedPoint.append(point)
                    if a == x and b == y:
                        nextEndPoint = point  # 끝점 갱신

        for point in addedPoint:
            dragonCurve[point[1]][point[0]] = n

        endX, endY = nextEndPoint
        addedPoint.clear()


N = int(input())  # 드래곤 커브 개수
for n in range(1, N+1):
    x, y, d, g = map(int, input().split())  # 시작점 (x, y), 시작방향 d, 세대 g
    generateG(x, y, d, g, n)

# 정사각형 개수 세기
numberSquares = 0
for x in range(MAX):
    for y in range(MAX):
        if dragonCurve[y][x] and dragonCurve[y][x+1] and dragonCurve[y+1][x] and dragonCurve[y+1][x+1]:
            numberSquares += 1

print(numberSquares)
