import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())
bibaragi = [list(map(int, input().split())) for _ in range(N)]
dir = [(0, -1), (-1, -1), (-1, 0),
       (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]

cloud = deque([(N - 1, 0), (N - 1, 1), (N - 2, 0), (N - 2, 1)])


def raining(d, s):
    cloudNum = len(cloud)
    for _ in range(cloudNum):
        r, c = cloud.popleft()
        # 구름 이동
        cloudR = (r + dir[d][0] * s) % N
        cloudC = (c + dir[d][1] * s) % N
        # if 0 > cloudR:
        #    cloudR += N
        # if 0 > cloudC:
        #    cloudC += N
        cloud.append((cloudR, cloudC))  # 물이 증가한 칸 표시
        visited[cloudR][cloudC] = True  # 구름이 사라진 자리 표시
        bibaragi[cloudR][cloudC] += 1


def waterBug():
    # for _ in cloud:
    while cloud:
        r, c = cloud.popleft()
        for d in range(1, 8, 2):
            cloudR = r + dir[d][0]
            cloudC = c + dir[d][1]
            if 0 <= cloudR < N and 0 <= cloudC < N and bibaragi[cloudR][cloudC] > 0:
                bibaragi[r][c] += 1


for _ in range(M):
    d, s = map(int, input().split())
    visited = [[False] * N for _ in range(N)]
    raining(d - 1, s)
    waterBug()
    # 구름 생성
    for r in range(N):
        for c in range(N):
            if bibaragi[r][c] >= 2 and not visited[r][c]:
                cloud.append((r, c))
                bibaragi[r][c] -= 2

total = 0
for i in range(N):
    for j in range(N):
        total += bibaragi[i][j]
print(total)
