N = int(input())

start = 2
for i in range(N):
    start = start * 2 - 1

print(start * start)