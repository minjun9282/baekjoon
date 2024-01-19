N = int(input())
max_prize = -1
prize = -1
for i in range(N):
    num_1, num_2, num_3 = map(int, input().split())
    if (num_1 == num_2) and (num_1 == num_3):
        prize = 10000 + num_1 * 1000
    elif (num_1 == num_2) and (num_1 != num_3):
        prize = 1000 + num_1 * 100
    elif (num_1 == num_3) and (num_1 != num_2):
        prize = 1000 + num_1 * 100
    elif (num_2 == num_3) and (num_2 != num_1):
        prize = 1000 + num_2 * 100
    else:
        prize = max(num_1, num_2, num_3) * 100
    if (prize > max_prize):
        max_prize = prize
        
print(max_prize)