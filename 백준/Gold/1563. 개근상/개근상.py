#  O를 출석, L을 지각, A를 결석
#  지각 두 번 이상/ 결석을 세 번 연속 -> 개근상 받지 못함
import sys
sys.setrecursionlimit(10**6)
N = int(input())

memoization = {}  # Memoization을 위한 딕셔너리

def perfect_attendance(character, rem_days, num_L, continual_abs):
    # Memoization 체크
    if (character, rem_days, num_L, continual_abs) in memoization:
        return memoization[(character, rem_days, num_L, continual_abs)]
    
    # 개근상 조건 체크
    if continual_abs == 3 or num_L > 1:
        return 0
    # 모든 날이 지나면 1을 반환
    if rem_days == 0:
        return 1
    
    count = 0
    if character == 'O':
        count = (
            perfect_attendance('O', rem_days - 1, num_L, 0) +
            perfect_attendance('L', rem_days - 1, num_L + 1, 0) +
            perfect_attendance('A', rem_days - 1, num_L, 1)
        )
    elif character == 'L':
        count = (
            perfect_attendance('O', rem_days - 1, num_L, 0) +
            perfect_attendance('A', rem_days - 1, num_L, 1)
        )
    else:  # character == 'A'
        count = (
            perfect_attendance('O', rem_days - 1, num_L, 0) +
            perfect_attendance('L', rem_days - 1, num_L + 1, 0) +
            perfect_attendance('A', rem_days - 1, num_L, continual_abs + 1)
        )
    
    # Memoization에 결과 기록
    memoization[(character, rem_days, num_L, continual_abs)] = count
    
    return count

result = (
    perfect_attendance('O', N-1, 0, 0) +
    perfect_attendance('L', N-1, 1, 0) +
    perfect_attendance('A', N-1, 0, 1)
)

print(result % 1000000)