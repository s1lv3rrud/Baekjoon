import sys
input = sys.stdin.readline

n = int(input())
stair = [int(input()) for _ in range(n)]

if(n < 3):
    print(sum(stair))
else:
    dp = [0 for _ in range(n)]
    dp[0] = stair[0]
    dp[1] = stair[0] + stair[1]
    for i in range(2, n):
        dp[i] = max(stair[i]+dp[i-2], stair[i]+stair[i-1]+dp[i-3])
    print(dp[-1])