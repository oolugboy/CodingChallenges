n, m, k = tuple(map(int, input().split(' ')))
a = []
for i in range(0, n):
    row_list = list(map(int, input().split(' ')))
    a.append(sort(row_list, reverse=True))

test_sum = 0
for i in range(0, n):
    for j in range(0, (m/2)):
        max_sum += a[i][i]

multiplier = test_sum/k

while multiplier > 0:
    



print(multiplier * k)


        


factors_found = 0

for matrix_elem in sorted_matrix_elems:
    if row_entries_picked[matrix_elems[i].row] < (m / 2):
        for prime_factor in k_prime_factors:
            
