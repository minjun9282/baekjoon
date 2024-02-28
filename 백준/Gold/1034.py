from itertools import permutations
import copy
N, M = map(int, input().split()) #행, 열의 갯수

lights = []
for i in range(N):
    lights.append(list(map(int, str(input()))))

K = int(input()) #스위치를 K번 눌러서 켜져있는 행을 최대로 함. - 해당 열에 있는 모든 램프의 상태를 변경함
## 각 열에 대해 짝수번 스위치를 누를 경우 안바꾼것과 동일하다는 것을 고려
## K가 5 열이 3 -> 100 111 가능, K가 6 열이 4 -> 0000, 0011, 1111가능, K가 5 열이 6 -> 111110 111000 100000가능..
def push_switch(lights_list, switch_case):
    # switch_case를 반복하여 lights 리스트 업데이트
    for i, switch in enumerate(switch_case):
        if switch == 'o':
            for j in range(len(lights)):
                # 0은 1로, 1은 0으로 변경
                lights_list[j][i] = 1 - lights_list[j][i]  
        
    return lights_list
    
def cal_num_lights_on(lights_list):
    result = 0
    for i in range(len(lights_list)):
        if 0 not in lights_list[i]:
            result += 1
            
    return result
    
def cal_max_result(lights_list):
    max_result = 0
    num_push_switch = [] #열별로 스위치를 누르는 횟수의 총합
    switch_case = []
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
    
    len_num_push_switch = len(num_push_switch)
    for i in range(len_num_push_switch):
        num_push_switch.append(['o'] * num_push_switch[i] + ['x']*(M-num_push_switch[i]))
    del num_push_switch[0:len_num_push_switch]
    
    #스위치를 켜는 모든 경우의 수 계산
    for i in range(len_num_push_switch):
        switch_case.extend(set(permutations(num_push_switch[i])))
    
    for i in range(len(switch_case)):
        temp_lights_list = copy.deepcopy(lights_list)
        temp_modified_lights_list = push_switch(temp_lights_list, switch_case[i])
        temp_result = cal_num_lights_on(temp_modified_lights_list)
        if temp_result > max_result:
            max_result = temp_result
          
    return max_result

print(cal_max_result(lights))