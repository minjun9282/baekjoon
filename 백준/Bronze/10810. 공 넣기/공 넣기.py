N, M = map(int, input().split())
basket = [0 for i in range(N + 1)]
for l in range(M):
    i, j, k = map(int, input().split())
    for m in range(i, j + 1):
        basket[m] = k

for n in range(1, N + 1):
    print(basket[n], end = ' ')