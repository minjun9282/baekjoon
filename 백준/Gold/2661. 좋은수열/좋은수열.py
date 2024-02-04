N = int(input())

results = "1"
num_len = len(results)
num = ["1", "2", "3"]
impossible_num_list = []

def good_sequence(text):
    test_times = 1
    bool_good_sequence = True
    while (test_times <= len(text) // 2):
        if (text[-2 * test_times: -1 * test_times] == text[-1 * test_times:]):
            bool_good_sequence = False
            break
        else:
            test_times += 1
    return bool_good_sequence
    

while (num_len != N):
    i = 0
    while (i < 3):
        if (num[i] != results[-1:]) and (good_sequence(results + num[i]) == True) and (results + num[i]) not in impossible_num_list: # and ((results + num[i]) not in impossible_num_list)
            results += num[i]
            num_len = len(results)
            break
        else:
            i += 1
    if i == 3:
        impossible_num_list.append(results)
        results = results[:-1]
        num_len = len(results)
    if num_len == N:
        break

print(results)