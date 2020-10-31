query_am = int(input())

entry_stack = list()
queue_stack = list()

for q in range(0, query_am):
    query = list(input().split(' '))
    if(query[0] == '1'):
        entry_stack.append(query[1])
    else:
        if(len(queue_stack) == 0):
            while(len(entry_stack) > 0):
                queue_stack.append(entry_stack.pop())
        if(query[0] == '2'):
            queue_stack.pop()
        if(query[0] == '3'):
            print(queue_stack[-1])


            

    
