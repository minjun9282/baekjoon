rows = 100
cols = 100
arr = [[0 for j in range(cols)] for i in range(rows)]

cpaper_Num = int(input())
for i in range(cpaper_Num):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            if arr[i][j] != 1:
                arr[i][j] = 1

sum = 0
for i in range(100):
    sum += arr[i].count(1)
    
print(sum)