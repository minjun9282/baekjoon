import math

n = int(input())
pib_dict = {}
def pibonacci(n):
    if n in pib_dict:
        return pib_dict[n]
    else:
        if n >= 0 and n <= math.pi:
            pib_dict[n] = 1
        else:
            pib_dict[n] = pibonacci(n-1) + pibonacci(n-math.pi)
        return pib_dict[n]

print(pibonacci(n) % 1000000000000000000)