H, W, N, M = map(int, input().split())
num_N = H // (1 + N)
num_M = W // (1 + M)

if ((H) % (1 + N)) != 0:
    num_N += 1
if ((W) % (1 + M)) != 0:
    num_M += 1

print(num_N * num_M)