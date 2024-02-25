import math

N = int(input())
# 1~N까지의 모든 수의 최소 공배수 찾기
number_list = [True] * (N+1)

for i in range(2, int(math.sqrt(N)) + 1):
    if number_list[i] == True:
        for j in range(i+i, N+1, i):
            number_list[j] = False

prime_number_list = [i for i in range(2, N+1) if number_list[i] == True]


result = 1
N_sqrt = math.sqrt(N)
for i in range(len(prime_number_list)):
    temp = prime_number_list[i]
    j = 1
    if temp > N_sqrt:
        result = int(result * temp % 987654321)
    else:
        while(temp < N):
            j += 1
            temp = math.pow(prime_number_list[i], j)
            if temp > N:
                temp = math.pow(prime_number_list[i], j - 1)
                break
        result = int(result * temp % 987654321)

print(result)