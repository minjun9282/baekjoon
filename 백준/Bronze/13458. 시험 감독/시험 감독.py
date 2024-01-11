import math

N = int(input())
Ai_list = list(map(int, input().split()))
B, C = map(int, input().split())
min_supervisor = 0

for i in range(N):
    if Ai_list[i] < (B + 1):
        min_supervisor += 1
    else:
        min_supervisor += (1 + math.ceil((Ai_list[i] - B) / C))

print(min_supervisor)