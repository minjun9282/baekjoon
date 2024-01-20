N, M = map(int, input().split())
board = []
starts_with_B = ["BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",]
starts_with_W = ["WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",]
cut_board = []
min_change = 64
idx = 0

for i in range(N):
    board.append(input())

for i in range(N - 7):
    for j in range(M - 7):
        for h in range(8):
            cut_board.append(board[i+h][j:j+8])
        temp = 0
        for k in range(8):
            for l in range(8):
                if cut_board[k][l] != starts_with_B[k][l]:
                    temp += 1
        if temp < min_change:
            min_change = temp
        temp = 0
        for k in range(8):
            for l in range(8):
                if cut_board[k][l] != starts_with_W[k][l]:
                    temp += 1
        if temp < min_change:
            min_change = temp
        cut_board = []

print(min_change)