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

    def empty(self):
        len = self.size()
        if len == 0:
            return 1
        else:
            return 0

    def top(self):
        len = self.size()
        if len == 0:
            return -1
        else:
            return self.list[len-1]
        
n = int(input())
stack = stack()
for i in range(n):
    x = input().split()
    if x[0] == "push":
        stack.push(int(x[1]))
    elif x[0] == "pop":
        print(stack.pop())
    elif x[0] == "size":
        print(stack.size())
    elif x[0] == "empty":
        print(stack.empty())
    elif x[0] == "top":
        print(stack.top())
