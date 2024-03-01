from itertools import permutations
import copy
N, M = map(int, input().split()) #행, 열의 갯수

lights = []
for i in range(N):
    lights.append(list(map(int, str(input()))))

K = int(input()) #스위치를 K번 눌러서 켜져있는 행을 최대로 함. - 해당 열에 있는 모든 램프의 상태를 변경함
## 각 열에 대해 짝수번 스위치를 누를 경우 안바꾼것과 동일하다는 것을 고려
## K가 5 열이 3 -> 100 111 가능, K가 6 열이 4 -> 0000, 0011, 1111가능, K가 5 열이 6 -> 111110 111000 100000가능..

def cal_max_result(lights_list, M, K):
    max_result = 0
    num_push_switch = [] #열별로 스위치를 누르는 횟수의 총합
    if K > M:
        if K % 2 == 0:  # K가 짝수인 경우
            for j in range(0, M+1, 2):
                num_push_switch.append(j)
        else:  # K가 홀수인 경우
            for j in range(1, M+1, 2):
                num_push_switch.append(j)
    else:
        for j in range(K, -1, -2):
            num_push_switch.append(j)
    
    for i in range(len(lights)):
        num_zero = lights[i].count(0)
        if num_zero in num_push_switch:
            num_same_row = lights.count(lights[i])
            if num_same_row > max_result:
                max_result = num_same_row
                
    return max_result
 
print(cal_max_result(lights, M, K))