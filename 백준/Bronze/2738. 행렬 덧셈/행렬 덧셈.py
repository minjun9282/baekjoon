N, M = map(int, input().split())
arr = [[0 for j in range(M)] for i in range(N)]
for i in range(N):
    elements = list(map(int, input().split()))
    for j in range(M):
        arr[i][j] += elements[j]
        
for i in range(N):
    elements = list(map(int, input().split()))
    for j in range(M):
        arr[i][j] += elements[j]

for i in range(N):
    for j in range(M):
        print(arr[i][j] , end = ' ')