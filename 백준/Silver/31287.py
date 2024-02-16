N, K = map(int, input().split()) # 문자열 S의 길이, S를 K번 이어 붙인 문자열이 T 
S = input() # 주어진 문자열 U:위, D:아래, l:왼, R: 오른쪽

## 문자열 T를 따라 움직이는 동안 원점에 다시 방문하는 경우가 있으면 "YES", 없으면 "NO" 출력

direction_list = [0, 0] #좌우(-1 <-> 1), 아래위(-1 <-> 1) 좌표

def add_direction(direction_list, letter): #주어진 문자에 따라 좌표를 수정
    if letter == 'U':
        direction_list[1] += 1
    elif letter == 'D':
        direction_list[1] -= 1
    elif letter == 'L':
        direction_list[0] -= 1
    else:
        direction_list[0] += 1

# 일단 T의 첫번째 시작 문자에 따라 타카하시가 이동한첫 좌표를 계산해줌
add_direction(direction_list, S[0])

#이제 T를 따라움직이는 동안 원점에 다시 방문하는 경우가 있는지를 검사함
comeback = False
i = 1 # S에 포함된 문자를 다루는 인덱스
j = 1 # S를 몇번 이어 붙였는지를 확인하는데 사용하는 인덱스
    
while (j < K + 1):
    add_direction(direction_list, S[i])
    if direction_list.count(0) == 2: #좌우 좌표와 아래위 좌표가 모두 0이면 원점을 지난 것임.
        comeback = True
        break;
    i += 1
    if i == N:
        i = 0
        j += 1

if comeback == True:
    print("YES")
else:
    print("NO")

