def solution(survey, choices):
    answer = ''
    score = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    for s, c in zip(survey, choices):
        if c < 4:
            score[s[0]] += 4 - c
        elif c > 4:
            score[s[1]] += c - 4

    keys = list(score.keys())
    values = list(score.values())

    for i in range(0, len(keys), 2):
        if values[i] >= values[i+1]:
            answer += keys[i]
        else:
            answer += keys[i+1]
        
    return answer