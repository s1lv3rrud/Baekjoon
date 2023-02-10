import sys
input = sys.stdin.readline

n, m = map(int, input().split())

board = list(input() for i in range(n))

def getColorNum(chess):
    numW = 0
    numB = 0
    # 0, 0 == "W"
    for x in range(0, 8, 2):
        for y in range(1, 8, 2):
            if(chess[x][y] == "W"):
                numW+=1
        for y in range(0, 8, 2):
            if(chess[x][y] == "B"):
                numW+=1
    
    for x in range(1, 8, 2):
        for y in range(0, 8, 2):
            if(chess[x][y] == "W"):
                numW+=1
        for y in range(1, 8, 2):
            if(chess[x][y] == "B"):
                numW+=1

    # 0, 0 == "B"
    for x in range(0, 8, 2):
        for y in range(1, 8, 2):
            if(chess[x][y] == "B"):
                numB+=1
        for y in range(0, 8, 2):
            if(chess[x][y] == "W"):
                numB+=1
    
    for x in range(1, 8, 2):
        for y in range(0, 8, 2):
            if(chess[x][y] == "B"):
                numB+=1
        for y in range(1, 8, 2):
            if(chess[x][y] == "W"):
                numB+=1

    return numW if numW < numB else numB


chess = []
minnum = 2500
for x in range(m-8+1):
    for y in range(n-8+1):
        chess = list(board[i][x:x+8] for i in range(y, y+8))
        num = getColorNum(chess)
        minnum = num if num < minnum else minnum 

print(minnum)