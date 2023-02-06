import sys
input = sys.stdin.readline

while(True):
    num = list(map(int, input().split()))
    if(num[0] == 0 & num[1] == 0 & num[2] == 0):
        break
    
    maxnum = max(num)
    num.remove(maxnum)

    if(num[0]**2 + num[1]**2 == maxnum**2):
        print("right")
    else:
        print("wrong")