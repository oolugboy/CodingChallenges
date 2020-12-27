import math

t = int(input())

def get_non_singleton_block_ind(blocks, start_ind, block_amount):
    for j in range(start_ind, block_amount):
        if blocks[j] > 1:
            return j
    return block_amount

def get_repeat_string_blocks(s):
    blocks = []
    prev_item = ''
    for i in range(0, len(s)):
        if s[i] != prev_item:
            blocks.append(1)
            prev_item = s[i]
        else:
            blocks[len(blocks) - 1] += 1
    return blocks
    
for case in range(0, t):
    n = int(input())
    s = list(input())
    blocks = get_repeat_string_blocks(s)
    
    max_steps = 0
    blocks_removed = 0
    block_amount = len(blocks)

    non_singleton_block_ind = -1

    for i in range(0, block_amount):
        if non_singleton_block_ind < i or blocks[non_singleton_block_ind] == 1:
            non_singleton_block_ind = get_non_singleton_block_ind(blocks, max(i, non_singleton_block_ind), block_amount)
        if non_singleton_block_ind == block_amount:
            break;
        blocks[non_singleton_block_ind] -= 1
        max_steps += 1
        blocks_removed += 1
     
    blocks_remaining = block_amount - blocks_removed
    max_steps += int(math.ceil(blocks_remaining / float(2)))
    
    print(max_steps)

