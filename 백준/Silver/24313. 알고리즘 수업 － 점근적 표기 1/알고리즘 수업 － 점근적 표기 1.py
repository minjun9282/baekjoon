a_1, a_0 = map(int, input().split())
c = int(input())
n_0 = int(input())
if (c * n_0 >= a_1 * n_0 + a_0) and (c >= a_1):
    print(1)
else:
    print(0)