import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())

# N * N 배열
fireball = [[[] for _ in range(N)]for _ in range(N)]

# 초기 파이어볼 세팅
for _ in range(M):
    r, c, m, s, d = map(int, input().split())
    fireball[r-1][c-1].append([m, s, d])

# 방향
dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

# 마법사 상어 이동 명령
for _ in range(K):
    # 파이어볼 이동
    moved = [[[] for _ in range(N)]for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if fireball[i][j] != []:
                for m, s, d in fireball[i][j]:
                    r = (i + dir[d][0] * s) % N
                    c = (j + dir[d][1] * s) % N
                    moved[r][c].append([m, s, d])
    # 중복 파이어볼 확인
    for i in range(N):
        for j in range(N):
            if len(moved[i][j]) >= 2:
                movedM, movedS, movedD = 0, 0, 0
                dirOdd, dirEven = 0, 0
                # 질량, 속도, 방향 확인
                for m, s, d in moved[i][j]:
                    movedM += m
                    movedS += s
                    if d % 2:
                        dirOdd += 1
                    else:
                        dirEven += 1
                movedM //= 5  # 소수점 이하 버림
                if movedM == 0:
                    moved[i][j].clear()
                    continue
                movedS //= len(moved[i][j])
                if dirEven == len(moved[i][j]) or dirOdd == len(moved[i][j]):
                    moved[i][j].clear()
                    for d in [0, 2, 4, 6]:
                        moved[i][j].append([movedM, movedS, d])
                else:
                    moved[i][j].clear()
                    for d in [1, 3, 5, 7]:
                        moved[i][j].append([movedM, movedS, d])
    fireball = [row[:] for row in moved]

totalM = 0
for i in range(N):
    for j in range(N):
        if fireball[i][j] != []:
            for m, s, d in fireball[i][j]:
                totalM += m

print(totalM)
