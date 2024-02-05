from itertools import permutations

N = int(input())

A_list = list(map(int, input().split()))
num_operators = list(map(int, input().split()))
operators_sort = [] #사용되는 연산자들의 집합
operators_order = [] #사용되는 연산자들의 집합을 활용하여 순열을 계산한 것

for i in range(num_operators[0]):
    operators_sort.append('+')
for i in range(num_operators[1]):
    operators_sort.append('-')
for i in range(num_operators[2]):
    operators_sort.append('*')
for i in range(num_operators[3]):
    operators_sort.append('//')

for i in permutations(operators_sort):
    operators_order.append(i)

operators_order = list(set(operators_order))
for i in range(len(operators_order)):
    operators_order[i] = list(operators_order[i])

def del_mul_div(num_list, operators_order):
    new_num_list = num_list
    new_operators_order = operators_order
    while (True):
        if ('*' not in new_operators_order) and ('//' not in new_operators_order):
            break
        else:
            if '*' in new_operators_order:
                mul_idx = new_operators_order.index('*')
            else:
                mul_idx = len(new_operators_order)
            if '//' in new_operators_order:
                div_idx = new_operators_order.index('//')
            else:
                div_idx = len(new_operators_order)
            if mul_idx < div_idx:
                temp = new_num_list[mul_idx] * new_num_list[mul_idx + 1]
                new_num_list[mul_idx] = temp
                del new_num_list[mul_idx + 1]
                del new_operators_order[mul_idx]
            else:
                temp = new_num_list[div_idx] // new_num_list[div_idx + 1]
                new_num_list[div_idx] = temp
                del new_num_list[div_idx + 1]
                del new_operators_order[div_idx]
                
    return new_num_list, new_operators_order


def calculate(new_num_list, new_operators_order):
    result = new_num_list[0]
    for i in range(len(new_operators_order)):
        if new_operators_order[i] == '+':
            result += new_num_list[i+1]
        else:
            result -= new_num_list[i+1]
    return result


max_result = -1 * 1000000001
min_result = 1000000001

for i in range(len(operators_order)):
    copy_list = A_list[:] #shallow_copy를 써줘야 아래에 del_mul_div안에 input 주는 copy_list가 계속 A_list와 같게 유지됨.
    new_num_list, new_operators_order = del_mul_div(copy_list, operators_order[i])
    temp = calculate(new_num_list, new_operators_order)
    if temp > max_result:
        max_result = temp
    if temp < min_result:
        min_result = temp

print(max_result)
print(min_result)