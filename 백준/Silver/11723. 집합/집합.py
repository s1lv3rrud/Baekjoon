import sys
input = sys.stdin.readline

m = int(input())

bit = 0
for _ in range(m):
    order = input().split()

    if order[0] == "all":
        bit = (1 << 20) - 1
    elif order[0] == "empty":
        bit = 0
    else:
        num = int(order[1]) - 1
        if order[0] == 'add':
            bit |= (1 << num)
        elif order[0] == 'remove':
            bit &= ~(1 << num)
        elif order[0] == 'check':
            if bit & (1 << num) == 0:
                print(0)
            else:
                print(1)
        elif order[0] == 'toggle':
            # XOR
            bit = bit ^ (1 << num)