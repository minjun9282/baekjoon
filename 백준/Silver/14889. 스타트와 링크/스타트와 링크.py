from itertools import permutations, combinations
import math

N = int(input())
S = []
min_diff = 1000
for i in range(N):
    S.append(list(map(int, input().split())))

nums = list(i for i in range(N))
nums_comp = []
comb = list(combinations(nums, (N // 2)))

for i in range(len(comb)):
    nums_comp.append(list(set(nums) - set(comb[i])))

del comb[(len(comb)//2):(len(comb))]
del nums_comp[(len(nums_comp)//2):(len(nums_comp))]

for i in range(len(comb)):
    sum_nums = 0
    sum_nums_comp = 0
    nums_permut_list = list(permutations(comb[i], 2))
    nums_comp_permut_list = list(permutations(nums_comp[i], 2))
    for j in range(len(nums_permut_list)):
        sum_nums += S[(nums_permut_list[j][0])][(nums_permut_list[j][1])]
        sum_nums_comp += S[(nums_comp_permut_list[j][0])][(nums_comp_permut_list[j][1])]
    
    if (abs(sum_nums - sum_nums_comp) < min_diff):
        min_diff = abs(sum_nums - sum_nums_comp)

print(min_diff)
    