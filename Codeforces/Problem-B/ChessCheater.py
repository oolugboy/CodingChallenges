t = int(input())
for it in range(0, t):
    n, k = tuple(list(map(int, input().split(' '))))
    results = [char for char in input()]

    initial_score = 0
    loss_amount = 0

    for i in range(0, len(results)):
        if i > 0 and results[i] == 'W' and results[i - 1] == 'W':
            initial_score += 1
        if results[i] == 'L':
            loss_amount += 1

    k = min(k, loss_amount)
    initial_score += (n - loss_amount)
    
    streak_increase_added_score = 2 * k
    
    if loss_amount == n and streak_increase_added_score > 0:
        streak_increase_added_score -= 1

    streak_diffs = []
    current_streak_diff = 0
    streak_found = 0
    for i in range(0, n):
        if results[i] == 'W':
            streak_found = True
            if current_streak_diff != 0:
                streak_diffs.append(current_streak_diff)
                current_streak_diff = 0
        if results[i] == 'L' and streak_found:
            current_streak_diff += 1


    sorted_streak_diffs = sorted(streak_diffs)

    disjoint_streak_decrease_added_score = 0
    for i in range(0, len(sorted_streak_diffs)):
        if k >= sorted_streak_diffs[i]:
            disjoint_streak_decrease_added_score += 1
            k -= sorted_streak_diffs[i]
        else:
            break

    final_score = (initial_score + streak_increase_added_score + disjoint_streak_decrease_added_score)

    print(final_score)

