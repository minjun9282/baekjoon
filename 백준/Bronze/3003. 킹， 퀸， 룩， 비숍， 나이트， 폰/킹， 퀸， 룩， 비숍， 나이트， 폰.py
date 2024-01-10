right_pieces = [1, 1, 2, 2, 2, 8]
pieces = list(map(int, input().split()))
required_amounts = [(right_pieces[i] - pieces[i]) for i in range(6)]
for i in range(6):
    print(required_amounts[i], end = ' ')
