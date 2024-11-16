def sum_of_subrectangle_areas(test_cases):
    results = []
    for N in test_cases:
        total = (N * (N + 1) * (N + 2) // 6) ** 2
        results.append(total)
    return results
    
T = int(input())
test_cases = [int(input()) for _ in range(T)]

results = sum_of_subrectangle_areas(test_cases)
for result in results:
    print(result)