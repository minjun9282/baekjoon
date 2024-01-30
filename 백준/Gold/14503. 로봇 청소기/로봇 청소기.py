N, M = map(int, input().split())
r, c, d = map(int, input().split()) #d가 0:북쪽, 1:동쪽, 2:남쪽, 3:서쪽
room_lst = []

for i in range(N):
    lst = list(map(int, input().split())) #값이 0이면 청소되지 않은 빈 칸, 1이면 벽이 있는 것
    room_lst.append(lst)

"""
로봇 청소기는 다음과 같이 작동한다.

1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
1. 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
1. 반시계 방향으로 90도 회전한다.
2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
3. 1번으로 돌아간다.
"""

cleaned_room = 0

while(True):
    if (room_lst[r][c] == 0):
        cleaned_room += 1
        room_lst[r][c] = -1 #청소한 칸은 -1로 표시
    if ((room_lst[r-1][c] != 0) and (room_lst[r+1][c] != 0) and (room_lst[r][c-1] != 0) and (room_lst[r][c+1] != 0)):
        if d == 0:
            if room_lst[r+1][c] != 1:
                r += 1
            else:
                break
        elif d == 1:
            if room_lst[r][c-1] != 1:
                c -= 1
            else:
                break
        elif d == 2:
            if room_lst[r-1][c] != 1:
                r -= 1
            else:
                break
        else:
            if room_lst[r][c+1] != 1:
                c += 1
            else:
                break
    else:
        while(True):
            if d == 0:
                d = 3
                if room_lst[r][c-1] == 0:
                    c -= 1
                    break
            elif d == 1:
                d = 0
                if room_lst[r-1][c] == 0:
                    r -= 1
                    break
            elif d == 2:
                d = 1
                if room_lst[r][c+1] == 0:
                    c += 1
                    break
            else:
                d = 2
                if room_lst[r+1][c] == 0:
                    r += 1
                    break

print(cleaned_room)