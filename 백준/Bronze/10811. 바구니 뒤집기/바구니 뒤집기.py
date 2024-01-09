N, M = map(int, input().split())
basket = list((i + 1) for i in range(N))
for l in range(M):
    i, j = map(int, input().split())
    basket[i - 1:j] = list(reversed(basket[i - 1:j]))
    
for i in range(len(basket)):
    print(basket[i], end = ' ')