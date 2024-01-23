N, B = map(int, input().split())
num_list = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

sum = 0
i = 1
idx_list = []
while N != 0:
    share = N // B
    remainder = N % B
    idx_list.append(remainder)
    N = share
    i += 1

result = ""
for i in range(len(idx_list)):
    result += num_list[idx_list[len(idx_list) - 1 - i]]
    
print(result)