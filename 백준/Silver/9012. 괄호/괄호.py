import sys
input = sys.stdin.readline

class stack:
    def __init__(self):
        self.list = []

    def push(self, x):
        self.list.append(x)
    
    def pop(self):
        len = self.size()
        if len == 0:
            return -1
        else:
            re = self.list[len-1]
            del self.list[len-1]
            return re

    def size(self):
        return len(self.list)

    def top(self):
        len = self.size()
        if len == 0:
            return -1
        else:
            return self.list[len-1]
        
n = int(input())
for i in range(n):
    stk = stack()
    x = input()
    for j in range(len(x)-1):
        if x[j] == '(':
            stk.push(x[j])
        else:
            if stk.top() == '(':
                stk.pop()
            else:
                stk.push(x[j])
    if stk.size() == 0:
        print("YES")
    else:
        print("NO")