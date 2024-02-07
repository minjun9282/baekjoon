from itertools import permutations

N = int(input())

A_list = list(map(int, input().split()))
num_operators = list(map(int, input().split()))
operators_sort = [] #사용되는 연산자들의 집합
operators_order = [] #사용되는 연산자들의 집합을 활용하여 순열을 계산한 것

for i in range(4):
    if num_operators[i] >= N:
        num_operators[i] = N - 1

for i in range(num_operators[0]):
    operators_sort.append('+')
for i in range(num_operators[1]):
    operators_sort.append('-')
for i in range(num_operators[2]):
    operators_sort.append('*')
for i in range(num_operators[3]):
    operators_sort.append('//')

for i in permutations(operators_sort, (N - 1)):
    operators_order.append(i)

operators_order = list(set(operators_order))

def calculate(max_result, min_result, operators_order):
    i = 0 #A_list의 인덱스
    j = 0 #operators_order의 인덱스
    temp = A_list[i]
    while(j < len(operators_order)):
        while(i < N - 1):
            if operators_order[j][i] == '+':
                temp += A_list[i+1]
            elif operators_order[j][i] == '-':
                temp -= A_list[i+1]
            elif operators_order[j][i] == '*':
                temp *= A_list[i+1]
            elif operators_order[j][i] == '//':
                if temp < 0:
                    temp_inverse = -1 * temp
                    temp = (temp_inverse // A_list[i+1]) * -1
                else:
                    temp //= A_list[i+1]
            i += 1
            if i == N - 1:
                if temp > max_result:
                    max_result = temp
                break
        i = 0
        temp = A_list[i]
        j += 1

    i = 0
    j = 0
    temp = A_list[i]
    while(j < len(operators_order)):
        while(i < N - 1):
            if operators_order[j][i] == '+':
                temp += A_list[i+1]
            elif operators_order[j][i] == '-':
                temp -= A_list[i+1]
            elif operators_order[j][i] == '*':
                temp *= A_list[i+1]
            elif operators_order[j][i] == '//':
                if temp < 0:
                    temp_inverse = -1 * temp
                    temp = (temp_inverse // A_list[i+1]) * -1
                else:
                    temp //= A_list[i+1]
            i += 1
            if i == N - 1:
                if temp < min_result:
                    min_result = temp
                break
        i = 0
        temp = A_list[i]
        j += 1
    
    print(max_result)
    print(min_result)

max_result = -1 * 1000000001
min_result = 1000000001

calculate(max_result, min_result, operators_order)