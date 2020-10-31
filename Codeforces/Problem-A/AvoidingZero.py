import copy

t = int(input())

for run in range(0, t):
    n = input()
    a = input().split(' ')
    a = list(map(lambda x: int(x), a))

    a_sum = 0
    for a_elem in a:
        a_sum += a_elem

    if a_sum == 0:
        print('NO')
    else:
        if a_sum > 0:
            a.sort(reverse=True)
        else:
            a.sort()
        print('YES')
        for a_elem in a:
            print(f'{a_elem} ', end="")
        print("\n", end="")
        
