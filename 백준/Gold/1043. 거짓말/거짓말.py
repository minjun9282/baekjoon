import copy
# 진실을 알고 있는 사람이 참여한 파티에서는 거짓말 불가능 - 내가 거짓말을 한 사람이 다른 파티에서 진실을 알고있는 사람과 같은 파티에 참여해도 안됨.
# 거짓말을 할 수 있는 파티 개수의 최댓값을 구하기

N, M = map(int, input().split()) #사람의 수 N, 파티의 수 M

know_truth_list = list(map(int, input().split())) #이야기의 진실을 아는 사람의 수, 진실을 아는 사람의 번호

participation_list = []
for i in range(M):
    participation_list.append(list(map(int, input().split()))) #각 파티마다 오는 사람의 수, 번호

if know_truth_list[0] == 0:
    print(M)
else:
    caution_member_list = copy.deepcopy(know_truth_list[1:]) # 이 번호의 멤버 앞에서는 거짓말 하면 안됨
    temp_caution_member_list = copy.deepcopy(know_truth_list[1:])
    while (True):
        for i in range(M):
            for j in range(len(participation_list[i][1:])):
                intersection = list(set([participation_list[i][j+1]]).intersection(temp_caution_member_list))
                if intersection != []:
                    temp_caution_member_list = list(set().union(temp_caution_member_list, participation_list[i][1:]))
        if temp_caution_member_list != caution_member_list:
            caution_member_list = temp_caution_member_list
        else:
            break
    
    result = 0
    for i in range(M):
        possible = True
        j = 0
        while (j < len(participation_list[i][1:])):
            if participation_list[i][j+1] in caution_member_list:
                possible = False
                break
            else:
                j += 1
            
        if possible == True:
            result += 1
    
    print(result)