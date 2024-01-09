X = int(input())
N = int(input())
sum_a = 0
for i in range(N):
    a, b = map(int, input().split())
    sum_a += (a * b)
    
if (sum_a == X):
    print("Yes")
else:
    print("No")
   