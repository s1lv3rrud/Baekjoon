import sys

input = sys.stdin.readline

n = int(input())
have = sorted(map(int, input().split()))

m = int(input())
find = list(map(int, input().split()))

def binarysearch(f, have, first, last):
    if(first > last):
        return 0
    mid = int((first+last)/2)
    if f == have[mid]:
        return have[first:last+1].count(f)
    elif f > have[mid]:
        return binarysearch(f, have, mid+1, last)
    else:
        return binarysearch(f, have, first, mid-1)

count = {} #dictionary
for h in have:
    first = 0
    last = len(have)-1
    if h not in count:
        count[h] = binarysearch(h, have, first, last)

for f in find:
    if f in count:
        print(count[f], end = " ")
    else:
        print(0, end = " ")