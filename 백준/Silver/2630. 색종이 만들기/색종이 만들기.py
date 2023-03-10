import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
white = 0
blue = 0

def solve(x, y, n):
    global white, blue
    current_color = board[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if current_color != board[i][j]:
                solve(x, y, n//2)
                solve(x, y + n//2, n//2)
                solve(x + n//2, y, n//2)
                solve(x + n//2, y + n//2, n//2)
                return

    if current_color == 0:
        white += 1
    else:
        blue += 1

solve(0, 0, n)
print(white)
print(blue)