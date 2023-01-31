while True:
    word = input()
    if word == "0":
        break
    if word[::-1] == word:
        print("yes")
    else:
        print("no")