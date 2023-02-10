import sys
input = sys.stdin.readline

n = int(input())
word = list(input() for i in range(n))
word_set = set(word)
word = list(word_set)
word.sort()
word.sort(key = len)
for w in word:
    w = w.replace("\n", "")
    print(w)