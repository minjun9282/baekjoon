dish_list = list(input())
height = 10
for i in range(1, len(dish_list)):
    if dish_list[i] == dish_list[i-1]:
        height += 5
    else:
        height += 10

print(height)