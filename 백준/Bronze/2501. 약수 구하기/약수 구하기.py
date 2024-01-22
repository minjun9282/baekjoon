div = 1
k_th = 0
N, K = map(int, input().split())
while (True):
    if (N % div) == 0:
        k_th += 1
    if k_th == K or div > N:
        break
    div += 1

if div > N:
    print(0)
else:
    print(div)