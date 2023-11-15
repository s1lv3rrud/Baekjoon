import sys

input = sys.stdin.readline

R, C, T = map(int, input().split())
dust = [list(map(int, input().split())) for _ in range(R)]

dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def spread():
    spreadDust = [[0 for _ in range(C)] for _ in range(R)]
    for r in range(R):
        for c in range(C):
            if dust[r][c] != 0 and dust[r][c] != -1:
                spreadNum = 0
                for x, y in dir:
                    spreadR = r+x
                    spreadC = c+y
                    if 0 <= spreadR < R and 0 <= spreadC < C and dust[spreadR][spreadC] != -1:
                        spreadDust[spreadR][spreadC] += dust[r][c]//5
                        spreadNum += 1
                dust[r][c] -= dust[r][c]//5 * spreadNum

    for r in range(R):
        for c in range(C):
            dust[r][c] += spreadDust[r][c]


def fresh():
    airFresher = 0
    for i in range(R):
        if dust[i][0] == -1:
            if airFresher == 0:  # 위쪽 공기청정기 -> 반시계방향
                airFresher += 1
                for r in range(i-1, 0, -1):
                    dust[r][0] = dust[r-1][0]

                for c in range(C-1):
                    dust[0][c] = dust[0][c+1]

                for r in range(0, i):
                    dust[r][C-1] = dust[r+1][C-1]

                for c in range(C-1, 1, -1):
                    dust[i][c] = dust[i][c-1]
                dust[i][1] = 0

            else:  # 아래쪽 공기청정기 -> 시계 방향
                for r in range(i+1, R-1):
                    dust[r][0] = dust[r+1][0]

                for c in range(C-1):
                    dust[R-1][c] = dust[R-1][c+1]

                for r in range(R-1, i, -1):
                    dust[r][C-1] = dust[r-1][C-1]

                for c in range(C-1, 1, -1):
                    dust[i][c] = dust[i][c-1]
                dust[i][1] = 0


for _ in range(T):
    # 미세먼지 확산
    spread()
    # 공기청정기 작동
    fresh()


total = 2  # 공기청정기 두 칸
for i in range(R):
    for j in range(C):
        total += dust[i][j]
print(total)
