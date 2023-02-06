n = int(input())
array = sorted(map(int, input().split()))
m = int(input())
array2 = list(map(int, input().split()))

for a in array2:
    front, back, flag = 0, n-1, 0
    while front <= back:
        mid = int((front+back) / 2)
        if a == array[mid]:
            print(1)
            flag = 1
            break
        elif a > array[mid]:
            front = mid+1
        elif a < array[mid]:
            back = mid -1
    if flag == 0:
        print(0)