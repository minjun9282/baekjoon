N = int(input())

#수의 최대 길이는 8
words = []
digit_alphabet = [[1], [10], [100], [1000], [10000], [100000], [1000000], [10000000]]
alphabet_list = []
for i in range(N):
    words.append(input())

for i in range(N):
    for j in range(len(words[i])):
        digit_alphabet[len(words[i]) - 1 - j].append(words[i][j])
        alphabet_list.append((words[i][j], 0))
        
alphabet_list = list(set(alphabet_list))
for i in range(len(alphabet_list)):
    alphabet_list[i] = list(alphabet_list[i])

[] #a와 b가 10의자리에 동시에 등장하는데 b는 일의자리에도 등장한다면 b에 더 높은 수를 할당해줘야 한다.
assigned_num = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
for i in range(7, -1, -1):
    for j in range(1, len(digit_alphabet[i])):
        k = 0
        while(True):
            if digit_alphabet[i][j] == alphabet_list[k][0]:
                alphabet_list[k][1] += digit_alphabet[i][0]
                break
            else:
                k += 1

# 위에서 말한 것처럼 최고 자릿수가 같은 알파벳이더라도 최종 결과값을 더 크게 만들수 있는 알파벳에 큰 숫자를 할당
sorted_alphabet_list = sorted(alphabet_list, key=lambda x:x[1], reverse=True)
for i, item in enumerate(sorted_alphabet_list):
    item[1] = 9 - i

# 결과값 계산
result = 0

for i in range(len(digit_alphabet)):
    for j in range(1, len(digit_alphabet[i])):
        k = 0
        while(True):
            if digit_alphabet[i][j] == sorted_alphabet_list[k][0]:
                result += digit_alphabet[i][0] * sorted_alphabet_list[k][1]
                break
            else:
                k += 1

print(result)