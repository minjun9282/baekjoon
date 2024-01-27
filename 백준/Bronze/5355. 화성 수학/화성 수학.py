T = int(input())

for i in range(T):
    cases = list(input().split())
    num = float(cases[0])
    for i in range(1, len(cases)):
        if cases[i] == '@':
            num = num * 3
        elif cases[i] == '%':
            num += 5
        else:
            num -= 7
    result = "{:.2f}".format(num)
    print(result)