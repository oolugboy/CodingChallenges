def calculate_score(results, n):
    score = 0
    for i in range(0, n):
        if results[i] == 'W':
            score += 1
            if i > 0 and results[i - 1] == 'W':
                score += 1
    return score

t = int(input())
for it in range(0, t):
    n, k = tuple(list(map(int, input().split(' '))))
    results = [char for char in input()]

    changes_made = 0
    if changes_made < k:
        for i in range(1, n - 1):
            if results[i] == 'L' and results[i - 1] == 'W' and results[i + 1] == 'W':
                results[i] = 'W'
                changes_made += 1
                if changes_made == k:
                    break
    if changes_made < k:
        for i in range(0, n):
            left_win_check = i > 0 and results[i] == 'L' and results[i - 1] == 'W'
            right_win_check = i < (n - 1) and results[i] == 'L' and results[i + 1] == 'W'
            if left_win_check or right_win_check:
                results[i] = 'W'
                changes_made += 1
                if changes_made == k:
                    break
    if changes_made < k:
        for i in range(0, n):
            if results[i] == 'L':
                results[i] = 'W'
                changes_made += 1
                if changes_made == k:
                    break
    
    print(calculate_score(results, n))
