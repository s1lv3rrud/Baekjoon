from collections import deque

def solution(queue1, queue2):

    queue1, queue2 = deque(queue1), deque(queue2)
    sum1, sum2 = sum(queue1), sum(queue2)

    for answer in range(300000):
        if sum1 == sum2:
            break
        elif sum1 > sum2:
            element = queue1.popleft()
            sum1 -= element
            sum2 += element
            queue2.append(element)
        elif sum2 > sum1:
            element = queue2.popleft()
            sum2 -= element
            sum1 += element
            queue1.append(element)

    if answer == 300000-1:
        return -1
    return answer