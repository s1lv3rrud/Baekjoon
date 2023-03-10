import sys
input = sys.stdin.readline

# 결과값이 최대가 되려면
# 최대한 큰 수를 빼야 한다.
equation = input().rstrip()
result = equation.split('-')

min = 0

first = result[0].split('+')
for f in first:
    min += int(f)

for r in result[1:]:
    bracket = r.split('+')
    for b in bracket:
        min -= int(b)

print(min)