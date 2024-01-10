str_list = ["" for i in range(75)]

for i in range(5):
    input_list = list(input())
    for j in range(len(input_list)):
        str_list[i + j * 5] = input_list[j]
    
print(''.join(str_list))