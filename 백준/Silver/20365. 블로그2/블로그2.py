import sys
input = sys.stdin.readline

n = int(input())

color = input()

numR = 0
numB = 0

flag = 0 # R : 0 B : 1
if (color[0] == 'R'):
    flag = 0
    numR += 1    
else:
    flag = 1
    numB += 1
for c in color[1:n]:
    if (c == 'R') & (flag == 1):
        flag = 0
        numR += 1    
    elif (c == 'B') & (flag == 0):
        flag = 1
        numB += 1

if numR > numB:
    print(numB+1)
else:
    print(numR+1)