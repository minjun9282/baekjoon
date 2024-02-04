import math 

# RxC 크기의 격자판 (1, 1) 에서 시작
R, C, T = map(int, input().split())

current_status = [] #현재 미세먼지 상태를 저장
after_spread_status = [[0 for j in range(C)] for i in range(R)] #확산 후 미세먼지 상태를 저장

for i in range(R):
    current_status.append(list(map(int, input().split())))

## 공기청정기 동작 후 매 1초마다 벌어지는 일
#1. (r, c)에 있는 미세먼지는 인접한 4방향으로 확산됨.
## 인접한 방향에 공기청정기가 있거나(-1), 칸이 없으면(out of index) 그 방향으로는 확산이 일어나지 않음.
## 확산되는 양은 floor(A(r,c) / 5)이며 A(r, c)에는 [기존 양 - floor(A(r,c) / 5) * 확산된 방향] 만큼이 남음
air_purifier_Location = []
for i in range(R):
    for j in range(C):
        spread_possible = 0 #인접한 영역 중 확산이 일어날 수 있는 칸의 갯수
        if (current_status[i][j] > 0):
            if ((j > 0) and (current_status[i][j-1] != -1)):
                spread_possible += 1
                after_spread_status[i][j-1] += current_status[i][j] // 5
            if ((j+1 < C) and (current_status[i][j+1] != -1)):
                spread_possible += 1
                after_spread_status[i][j+1] += current_status[i][j] // 5
            if ((i > 0) and (current_status[i-1][j] != -1)):
                spread_possible += 1
                after_spread_status[i-1][j] += current_status[i][j] // 5
            if ((i+1 < R) and (current_status[i+1][j] != -1)):
                spread_possible += 1
                after_spread_status[i+1][j] = current_status[i][j] // 5
            after_spread_status[i][j] += current_status[i][j] - spread_possible * (current_status[i][j] // 5)
        elif (current_status[i][j] == -1):
            after_spread_status[i][j] = -1
            air_purifier_Location.append([i, j]) # 공기 청정기의 좌표 저장
            
#2. 공기청정기가 작동함 (공기 청정기는 항상 1열에 위치)
## 공기청정기에서는 바람이 나옴. 위쪽 공기 청정기는 반시계 방향으로 순환, 아랫쪽 공기청정기는 시계방향으로 순순환
## 바람이 불면 미세먼지가 바람의 방향으로 모두 한칸씩 이동함.
## 공기청정기로 들어간 미세먼지는 모두 정화됨.
# 위쪽 공기청정기 작동 후
x = air_purifier_Location[0][0]
y = air_purifier_Location[0][1]
after_spread_status[x][y+2:]
after_spread_status[x][y+1] = 0




#3. 최종 결과 산출
# air_purifier_Location의 첫번째 좌표가 위쪽 공기청정기(반시계), 두번째 좌표가 아랫쪽 공기청정기(시계 방향)
# 위쪽 공기청정기 바람의 영향을 받는 미세먼지를 리스트로 저장
result = 0
x = air_purifier_Location[0][0]
y = air_purifier_Location[0][1]

for i in range(1, x):
    for j in range(1, C-1):
        result += after_spread_status[i][j] #바람의 영향을 받지 않는 미세먼지 양은 미리 결과값에 저장
   
upper_Air = []
temp = []
temp.append(after_spread_status[x][y+1:C])
temp.append([row[C-1] for row in after_spread_status[x-1:0:-1]])
temp.append(after_spread_status[0][::-1])
temp.append([row[0] for row in after_spread_status[1:x]])
temp.append(after_spread_status[x][0:y])

for i in range(len(temp)):
    for j in range(len(temp[i])):
        upper_Air.append(temp[i][j])

# 아래쪽 공기청정기 바람의 영향을 받는 미세먼지를 리스트로 저장
lower_Air = []
temp = []

x = air_purifier_Location[1][0]
y = air_purifier_Location[1][1]
for i in range(x+1, R-1):
    for j in range(1, C-1):
        result += after_spread_status[i][j] #바람의 영향을 받지 않는 미세먼지 양은 미리 결과값에 저장
      
temp.append(after_spread_status[x][y+1:C])
temp.append([row[C-1] for row in after_spread_status[x+1:R-1]])
temp.append(after_spread_status[R-1][::-1])
temp.append([row[0] for row in after_spread_status[R-2:x:-1]])
temp.append(after_spread_status[x][0:y])

for i in range(len(temp)):
    for j in range(len(temp[i])):
        lower_Air.append(temp[i][j])

# 공기청정기가 T초 작동하면 upper_Air과 lower_Air에서 각각 뒤 쪽의 T개의 원소는 사라지게 됨.
print('\n')
for i in range(R):
    for j in range(C):
        print(after_spread_status[i][j], end=' ')
    print('\n')
print('\n')
print(upper_Air)
print(lower_Air)
del upper_Air[-T:]
del lower_Air[-T:]
print("삭제후 upper_Air", upper_Air)
print("삭제후 lower_Air", lower_Air)

# 공기청정기의 영향을 받아 사라진 미세먼지를 제외하고 결과값에 더해줌
result += sum(upper_Air)
result += sum(lower_Air)

#최종 결과 출력
print(result)