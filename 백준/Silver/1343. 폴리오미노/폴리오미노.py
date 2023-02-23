import sys
input = sys.stdin.readline
# AAAA BB

def solve(board):
    board2 = ""
    num = 0
    for b in board:
        if b == 'X':
            num += 1
            if num == 4:
                num = 0
                board2 += "AAAA"
        else:
            if num % 2 != 0:
                return -1
            else:
                if b == '.':
                    if num == 2:
                        num = 0
                        board2 += "BB"
                    board2 += '.'
                else:
                    if num == 2:
                        board2 += "BB"
    
    if num % 2 != 0:
        return -1
    return board2
            

board =  input()
print(solve(board))

