n = int(input())
heights = list(map(lambda x: int(x), input().split(' '))) + [0]

stack = list()

push_it = 0
max_area = -1
while push_it < (n + 1):
    while(len(stack) > 0 and heights[push_it] < heights[stack[-1]]):
        top_ind = stack.pop()
        if(len(stack) > 0):
            if(heights[top_ind] == heights[stack[-1]]):
                continue;
            else:
                width = (push_it - stack[-1]) - 1
        else:
            width = push_it
        area = width * heights[top_ind]
        max_area = max(max_area, area)
    stack.append(push_it)
    push_it+=1

print(max_area)
