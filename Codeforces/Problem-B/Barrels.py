t = int(input())
for case in range(0, t):
    n, k = tuple(map(int, input().split(' ')))
    a = list(map(int, input().split(' ')))
    a.sort(reverse=True)

    if n == 1:
        print(a[0])
    else:
        max_barrel = a[0]
        if k == 0:
            min_barrel = a[1]
        else:
            min_barrel = 0
            for i in range(0, k):
                max_barrel += a[i + 1]
    print(max_barrel - min_barrel)
