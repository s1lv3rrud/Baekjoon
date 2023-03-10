import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
color0 = 0
color1 = 0
color_1 = 0

def solve(x, y, n):
    global color0, color1, color_1
    current_color = board[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if current_color != board[i][j]:
                solve(x, y, n//3)
                solve(x, y + n//3, n//3)
                solve(x, y + 2*n//3, n//3)
                solve(x + n//3, y, n//3)
                solve(x + n//3, y + n//3, n//3)
                solve(x + n//3, y + 2*n//3, n//3)
                solve(x + 2*n//3, y, n//3)
                solve(x + 2*n//3, y + n//3, n//3)
                solve(x + 2*n//3, y + 2*n//3, n//3)

                return

    if current_color == 0:
        color0 += 1
    elif current_color == 1:
        color1 += 1
    else:
        color_1 += 1

solve(0, 0, n)
print(color_1)
print(color0)
print(color1)