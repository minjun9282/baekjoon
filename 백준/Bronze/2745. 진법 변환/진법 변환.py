import math

N, B = map(str, input().split())
b_Notation = int(B)
num_list = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

sum = 0

for i in range(len(N)):
    num = int(num_list.index(N[i]))
    sum += num * pow(b_Notation, len(N) - 1 - i)

print(sum)