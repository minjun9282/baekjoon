T = int(input())
for i in range(T):
    C = int(input())
    num_Quarter = C // 25
    num_Dime = (C % 25) // 10
    num_Nickel = ((C % 25) % 10) // 5
    num_Penny = (((C % 25) % 10) % 5)
    print(num_Quarter, num_Dime, num_Nickel, num_Penny)