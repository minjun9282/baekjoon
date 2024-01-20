N = int(input())
find = False
i = 665
n_th = 0
while (find != True):
    i += 1
    if "666" in str(i):
        n_th += 1
    if (n_th == N):
        break;

print(i)