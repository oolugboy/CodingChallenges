class Streak:
    def __init__(self, start_ind, end_ind):
        self.start_ind = start_ind
        self.end_ind = end_ind

class StreakNbors:
    def __init__(self, streak_a, streak_b):
        self.streak_a = streak_a
        self.streak_b = streak_b

    def get_gap(self):
        return (self.streak_b.start_ind - self.streak_a.end_ind) - 1

    def close_gap(self):
        self.streak_a.end_ind += 1

t = int(input())
for it in range(0, t):
    n, k = tuple(list(map(int, input().split(' '))))
    results = [char for char in input()]

    if n == 1:
        if k >= 1:
            results[0] = 'W'
    else:
        streak_list = []
        current_streak = None
        for i in range(0, len(results)):
            if results[i] == 'W':
                if i == 0 or results[i - 1] == 'L':
                    current_streak = Streak(i, i)
                    streak_list.append(current_streak)
                else:
                    current_streak.end_ind = i

        if streak_list:
            streak_nbors_list = []
            for i in range(0, len(streak_list) - 1):
                streak_nbors_list.append(StreakNbors(streak_list[i], streak_list[i + 1]))

            streak_nbors_list = sorted(streak_nbors_list, key=lambda streak_nbors: streak_nbors.get_gap())

            streak_nbors_ind = 0
            changes = 0
            while changes < k and streak_nbors_ind < len(streak_nbors_list):
                current_streak_nbors = streak_nbors_list[streak_nbors_ind]
                if current_streak_nbors.get_gap() > 0:
                    current_streak_nbors.close_gap()
                    changes += 1
                else:
                    streak_nbors_ind += 1

            for i in range(0, len(streak_nbors_list)):
                current_streak_nbors = streak_nbors_list[i]
                streak_a_start_ind = current_streak_nbors.streak_a.start_ind
                streak_a_end_ind = current_streak_nbors.streak_a.end_ind
                for j in range(streak_a_start_ind, streak_a_end_ind + 1):
                    results[j] = 'W'
            
                streak_b_start_ind = current_streak_nbors.streak_b.start_ind
                streak_b_end_ind = current_streak_nbors.streak_b.end_ind
                for j in range(streak_b_start_ind, streak_b_end_ind + 1):
                    results[j] = 'W'
        
            min_streak_ind = 200001
            max_streak_ind = -1

            for i in range(0, len(results)):
                if results[i] == 'W':
                    min_streak_ind = min(i, min_streak_ind)
                    max_streak_ind = max(i, min_streak_ind)

            while changes < k:
                if min_streak_ind > 0:
                    min_streak_ind -= 1
                    results[min_streak_ind] = 'W'
                    changes +=1
                elif max_streak_ind < len(results) - 1:
                    max_streak_ind += 1
                    results[max_streak_ind] = 'W'
                    changes += 1
                else:
                    break
        else:
            for i in range(0, k):
                results[i] = 'W'

    score = 0
    for i in range(0, n):
        if results[i] == 'W':
            score += 1
            if i > 0 and results[i - 1] == 'W':
                score += 1
    
    print(score)

