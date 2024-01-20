a, b, c, d, e, f = map(int, input().split())
find = False
x = -1000
while (find != True):
    x += 1
    for i in range(-999, 1000):
        y = i
        if (a * x + b * y == c) and (d * x + e * y == f):
            find = True
            break;

print(x, y)