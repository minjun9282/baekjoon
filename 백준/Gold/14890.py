import copy

N, L = map(int, input().split())
maps = []

for i in range(N):
    maps.append(list(map(int, input().split())))

maps_row = copy.deepcopy(maps)
maps_col = copy.deepcopy(maps)

def check_passable(map_list):
    passable = True
    i = 0
    while (i < len(map_list) - 1):
        if abs(map_list[i] - map_list[i+1]) > 0.5:
            passable = False
            break
        i += 1
    return passable

# 경사로 가로로 놓기
for i in range(N):
    for j in range(N - L):
        sublist = maps_row[i][j+1:j+1+L]
        if (maps_row[i][j] == maps_row[i][j+1] + 1) and (sublist.count(sublist[0]) == len(sublist)):
            maps_row[i][j+1] += 0.5
    for j in range(N - L + 1, 1, -1):
        sublist = maps_row[i][j-L:j]
        if (maps_row[i][j] == maps_row[i][j-1] + 1) and (sublist.count(sublist[-1]) == len(sublist)):
            maps_row[i][j-1] += 0.5

# 경사로 세로로 놓기
for j in range(N):
    for i in range(N - L):
        sublist = [row[j] for row in maps_col[i+1:i+1+L]]
        if (maps_col[i][j] == maps_col[i+1][j] + 1) and (sublist.count(sublist[0]) == len(sublist)):
            maps_col[i+1][j] += 0.5
    for i in range(N - L + 1, 1, -1):
        sublist = [row[j] for row in maps_col[i-L:i]]
        if (maps_col[i][j] == maps_col[i-1][j] + 1) and (sublist.count(sublist[-1]) == len(sublist)):
            maps_col[i-1][j] += 0.5

for i in range(N):
    print(maps_row[i])
print('\n')

for i in range(N):
    print(maps_col[i])
print('\n')

result = 0   

# 가로 길에 대해 지나갈 수 있는 길 계산
for i in range(N):
    if check_passable(maps_row[i]) == True:
        result += 1
print(result)

# 세로 길에 대해 지나갈 수 있는 길 계산
for i in range(N):
    sublist = [row[i] for row in maps_col[:]]
    if check_passable(sublist) == True:
        result += 1
print(result)

# 가로길과 세로길이 동시에 통행가능하나 경사로가 겹칠 경우 한개 제외
for i in range(N):
    for j in range(N):
        if type(maps_row[i][j]) == float:
            sublist = [row[i] for row in maps_col[:]]
            if check_passable(maps_row[i]) == True and check_passable(sublist) == True:
                result -= 1

print(result)
    