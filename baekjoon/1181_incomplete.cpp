#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string* words = new string[N];
	int* length = new int[N];
	int* rank = new int[N];
	
	// 첫번째 단어 입력받기
	int num_words = 0;
	cin >> words[0];
	length[0] = words[0].length();
	rank[0] = 0;
	num_words++;

	// 두번째 단어~마지막 단어 입력받기

	int i = 1;
	bool found = false;
	string temp;
	int temp_rank;
	while (i < N) {
		cin >> temp;
		found = false;
		for (int j = 0; j < num_words; j++) {
			if (words[j] == temp) {
				found = true;
			}
		}
		if (found != true) {
			words[num_words] = temp;
			length[num_words] = temp.length();
			// 단어간의 정렬을 여기서 진행해야함. 길이가 짧은거 먼저 -> 사전순
			for (int k = 0; k < num_words; k++) {
				if (length[num_words] < length[k]) {
					rank[num_words] = rank[k];
					rank[k]++;
				}

			}
			num_words++;
			
		}
		i++;
	}

	// 조건에 따라 단어 순서 정렬하기


	// 조건에 따라 정렬한 결과 출력
	for (int i = 0; i < num_words; i++) {
		cout << words[i] << " " << length[i] << " " << rank[i] << '\n';
	}
	return 0;
}