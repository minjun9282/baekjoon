index_row = 0
index_col = 0
max_val = 0
for i in range(9):
    input_lst = list(map(int, input().split()))
    if max(input_lst) >= max_val:
        max_val = max(input_lst)
        index_row = i + 1
        index_col = input_lst.index(max_val) + 1

print(max_val)
print(index_row, index_col)