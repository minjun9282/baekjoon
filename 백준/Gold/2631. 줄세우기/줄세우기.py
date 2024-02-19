# 번호 순서대로 배치하기 위해 옮겨지는 아이의 최소 수를 구하기
N = int(input()) # 아이의 수
kids_num_list = []
for i in range(N):
    number = int(input())
    kids_num_list.append(number)
    
# kids_num_list에 있는 수들을 이용하여 오름차순으로 증가하는 배열의 최대 길이를 찾고, 그 배열을 구성하는 수는 그 자리에 그대로 둠.
seq_length_list = [1 for i in range(N)]
for i in range(N):
    for j in range(i):
        if kids_num_list[j] < kids_num_list[i]:
            seq_length_list[i] = max(seq_length_list[i], seq_length_list[j] + 1)

print(N - max(seq_length_list))