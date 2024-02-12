from itertools import permutations

N = int(input())

A_list = list(map(int, input().split()))
num_operators = list(map(int, input().split()))


for i in range(4):
    if num_operators[i] >= N:
        num_operators[i] = N - 1

def calculate(num_list, num_operators, temp_result):
    if len(num_list) == 0:
        return temp_result, temp_result
        
    result_arr = []
    
    if num_operators[0] != 0:
        num_operators[0] -= 1
        result_arr.extend(calculate(num_list[1:], num_operators, temp_result + num_list[0]))
        num_operators[0] += 1
    if num_operators[1] != 0:
        num_operators[1] -= 1
        result_arr.extend(calculate(num_list[1:], num_operators, temp_result - num_list[0]))
        num_operators[1] += 1
    if num_operators[2] != 0:
        num_operators[2] -= 1
        result_arr.extend(calculate(num_list[1:], num_operators, temp_result * num_list[0]))
        num_operators[2] += 1
    if num_operators[3] != 0:
        num_operators[3] -= 1
        result_arr.extend(calculate(num_list[1:], num_operators, int(temp_result / num_list[0])))
        num_operators[3] += 1
    
    return max(result_arr), min(result_arr)

max_result, min_result = calculate(A_list[1:], num_operators, A_list[0])

print(max_result)
print(min_result)