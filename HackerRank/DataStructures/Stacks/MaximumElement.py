N = int(input())

elem_stack = list()
max_stack = list()

for i in range(0, N):
    query = list(map(lambda x: int(x), input().split(' ')))
    if query[0] == 1:
        elem_stack.append(query[1])
        if len(max_stack) == 0 or query[1] >= max_stack[-1]:
            max_stack.append(query[1])
    elif query[0] == 2:
        top_elem = elem_stack.pop()
        if top_elem == max_stack[-1]:
            max_stack.pop()
    else:
        print(max_stack[-1])
    
    
    
