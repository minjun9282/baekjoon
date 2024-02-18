n = int(input())

# 제일 마지막 부분에 건물이 끝난 다는 의미로 (1000001, 0)을 추가해줌.
changing_point_list = []
for i in range(n):
    x, y = map(int, input().split())
    changing_point_list.append([x, y])
changing_point_list.append([100001, 0])

# 건물의 y좌표를 stack에 추가함
## 새로운 y좌표가 기존에 있던 y좌표보다 크면 건물의 갯수를 한개 추가한 후 새로운 y좌표를 stack에 추가
## 새로운 y좌표가 기존에 있던 y좌표보다 작다면 기존에 있던 last y좌표가 새로운 y좌표보다 작거나 같아질때까지 stack에 있는 수를 제거
### 새로운 y좌표가 stack에 남아있는 last y좌표와 다르다면(더 크다면) 새로운 y좌표를 stack에 추가한 후 건물의 갯수도 한개 추가

stack = [0] #처음 시작에 건물이 없다는 default값으로 0을 추가해줌
num_buildings = 0
for i in range(n):
    if changing_point_list[i][1] > stack[-1]:
        stack.append(changing_point_list[i][1])
        num_buildings += 1
    elif changing_point_list[i][1] < stack[-1]:
        while stack[-1] > changing_point_list[i][1]:
            del stack[-1]
        if changing_point_list[i][1] != stack[-1]:
            stack.append(changing_point_list[i][1])
            num_buildings += 1
            
print(num_buildings)