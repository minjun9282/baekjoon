N, M = map(int, input().split())
basket = [(i + 1) for i in range(N)]
for l in range(M):
    i, j = map(int, input().split())
    copy = basket[i - 1]
    basket[i - 1] = basket[j - 1]
    basket[j - 1] = copy

for i in range(N):
    print(basket[i], end = ' ')

