# 톱니의 극이 다르면 반대방향으로 회전, 톱니의 극이 같으면 회전 x, 톱니의 극이 달라도 옆에 있는 애가 움직이는게 아니면 회전 x
# N극은 0, S극은 1
# 톱니는 총 4개
# 총 K번 회전시키며 (회전시킬 톱니바퀴의 번호, 회전 방향)이 입력으로 주어짐
# 1일 경우 시계방향 회전, -1일 경우 반시계 방향 회전

# 톱니의 극이 다르면 반대방향으로 회전, 톱니의 극이 같으면 회전 x, 톱니의 극이 달라도 옆에 있는 애가 움직이는게 아니면 회전 x
# N극은 0, S극은 1
# 톱니는 총 4개
# 총 K번 회전시키며 (회전시킬 톱니바퀴의 번호, 회전 방향)이 입력으로 주어짐
# 1일 경우 시계방향 회전, -1일 경우 반시계 방향 회전

from collections import deque

def rotate_clockwise(deq):
    s = deq.pop()
    deq.appendleft(s)
    
def rotate_counterclockwise(deq):
    s = deq.popleft()
    deq.append(s)

# 톱니바퀴 초기 입력
gear_first = deque(map(int, str(input())))
gear_second = deque(map(int, str(input())))
gear_third = deque(map(int, str(input())))
gear_fourth = deque(map(int, str(input())))

K = int(input())

for i in range(K):
    # 회전시킬지 말지 판단하는 변수
    rotate_first = False
    rotate_second = False
    rotate_third = False
    rotate_fourth = False
    
    target, direction = map(int, input().split())
    if target == 1:
        if gear_first[2] != gear_second[6]:
            rotate_second = True
            if gear_second[2] != gear_third[6]:
                rotate_third = True
                if gear_third[2] != gear_fourth[6]:
                    rotate_fourth = True
  
        if direction == 1:
            rotate_clockwise(gear_first)
            if rotate_second == True:
                rotate_counterclockwise(gear_second)
                if rotate_third == True:
                    rotate_clockwise(gear_third)
                    if rotate_fourth == True:
                        rotate_counterclockwise(gear_fourth)
        else:
            rotate_counterclockwise(gear_first)
            if rotate_second == True:
                rotate_clockwise(gear_second)
                if rotate_third == True:
                    rotate_counterclockwise(gear_third)
                    if rotate_fourth == True:
                        rotate_clockwise(gear_fourth)
    elif target == 2:
        if gear_second[6] != gear_first[2]:
            rotate_first = True
        if gear_second[2] != gear_third[6]:
            rotate_third = True
            if gear_third[2] != gear_fourth[6]:
                rotate_fourth = True
        
        if direction == 1:
            rotate_clockwise(gear_second)
            if rotate_first == True:
                rotate_counterclockwise(gear_first)
            if rotate_third == True:
                rotate_counterclockwise(gear_third)
                if rotate_fourth == True:
                    rotate_clockwise(gear_fourth)
        else:
            rotate_counterclockwise(gear_second)
            if rotate_first == True:
                rotate_clockwise(gear_first)
            if rotate_third == True:
                rotate_clockwise(gear_third)
                if rotate_fourth == True:
                    rotate_counterclockwise(gear_fourth)
    elif target == 3:
        if gear_third[6] != gear_second[2]:
            rotate_second = True
            if gear_second[6] != gear_first[2]:
                rotate_first = True
        if gear_third[2] != gear_fourth[6]:
            rotate_fourth = True
        
        if direction == 1:
            rotate_clockwise(gear_third)
            if rotate_second == True:
                rotate_counterclockwise(gear_second)
                if rotate_first == True:
                    rotate_clockwise(gear_first)
            if rotate_fourth == True:
                rotate_counterclockwise(gear_fourth)
        else:
            rotate_counterclockwise(gear_third)
            if rotate_second == True:
                rotate_clockwise(gear_second)
                if rotate_first == True:
                    rotate_counterclockwise(gear_first)
            if rotate_fourth == True:
                rotate_clockwise(gear_fourth)
    else:
        if gear_fourth[6] != gear_third[2]:
            rotate_third = True
            if gear_third[6] != gear_second[2]:
                rotate_second = True
                if gear_second[6] != gear_first[2]:
                    rotate_first = True
        if direction == 1:
            rotate_clockwise(gear_fourth)
            if rotate_third == True:
                rotate_counterclockwise(gear_third)
                if rotate_second == True:
                    rotate_clockwise(gear_second)
                    if rotate_first == True:
                        rotate_counterclockwise(gear_first)
        else:
            rotate_counterclockwise(gear_fourth)
            if rotate_third == True:
                rotate_clockwise(gear_third)
                if rotate_second == True:
                    rotate_counterclockwise(gear_second)
                    if rotate_first == True:
                        rotate_clockwise(gear_first)
            
points = 0
if gear_first[0] == 1:
    points += 1
if gear_second[0] == 1:
    points += 2
if gear_third[0] == 1:
    points += 4
if gear_fourth[0] == 1:
    points += 8

print(points)