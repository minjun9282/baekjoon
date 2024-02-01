grid = [[0 for j in range(101)] for i in range(101)]

def drgn_curve(x, y, d, g, grid, d_list):
    #시작점 (x, y)
    #방향 d: 0(오른쪽) 1(위쪽) 2(왼쪽) 3(아랫쪽)
    #드래곤 커브 세대 g
    # d_list에서 방향은 선을 이어나갈 때 쓰이며 시작 d에 따라 달라짐.
    if d == 0:
        d_list.append(0)
    elif d == 1:
        d_list.append(1)
    elif d == 2:
        d_list.append(2)
    else:
        d_list.append(3)
    
    # 드래곤 커브를 작성할 때 사용하는 방향에 대한 정보를 가진 리스트 작성
    for i in range(g):
        rotate(d_list)
    
    # 드래곤 커브를 활용하여 grid에 값을 표시하는 작업 (여기서는 x가 행이니세로축, y가 열이니가로축 인것 주의)
    grid[x][y] = 1
    if d == 0:
        start_x = x 
        start_y = y + 1
    elif d == 1:
        start_x = x - 1
        start_y = y 
    elif d == 2:
        start_x = x 
        start_y = y - 1
    else:
        start_x = x + 1
        start_y = y
        
    grid[start_x][start_y] = 1
    for j in range(1, len(d_list)):
        if d == 0 or d == 2: #선을 이어 나가는 방향 0: 오, 1:아래, 2: 왼, 3: 위
            if d_list[j] == 0:
                grid[start_x][start_y + 1] = 1
                start_y += 1
            elif d_list[j] == 3:
                grid[start_x - 1][start_y] = 1
                start_x -= 1
            elif d_list[j] == 2:
                grid[start_x][start_y - 1] = 1
                start_y -= 1
            else:
                grid[start_x + 1][start_y] = 1
                start_x += 1
        elif d == 1 or d == 3: #선을 이어 나가는 방향 0: 왼, 1: 위, 2: 오, 3: 아래
            if d_list[j] == 0:
                grid[start_x][start_y - 1] = 1
                start_y -= 1
            elif d_list[j] == 3:
                grid[start_x + 1][start_y] = 1
                start_x += 1
            elif d_list[j] == 2:
                grid[start_x][start_y + 1] = 1
                start_y += 1
            else:
                grid[start_x - 1][start_y] = 1
                start_x -= 1

def rotate(d_list): #세대 g에 따라 선을 이어나가는 방향에 대한 정보를 저장한 리스트를 생성
    for i in range(len(d_list) - 1, -1, -1):
        if d_list[i] == 0:
            d_list.append(3)
        elif d_list[i] == 1:
            d_list.append(0)
        elif d_list[i] == 2:
            d_list.append(1)
        else:
            d_list.append(2)
            
# 드래곤 커브의 개수 N과 드래곤 커브의 정보 입력받기
N = int(input())
d_list = []
for i in range(N):
    y, x, d, g = map(int, input().split()) # 시작점(x,y), d:시작방향(오른쪽, 위쪽 , 왼쪽, 아랫쪽, 세대 g
    drgn_curve(x, y, d, g, grid, d_list)
    d_list = []

#1x1 사각형의 갯수 출력
result = 0
for i in range(100):
    for j in range(100):
        if (grid[i][j] == 1) and (grid[i+1][j] == 1) and (grid[i][j+1] == 1) and (grid[i+1][j+1] == 1):
            result += 1

print(result)