#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	double num_of_con;
	string s;
	cin >> N;

	double* score = new double[N];
	int* size = new int[N];
	char** test_case = new char* [N];
	fill_n(score, N, 0);
	for (int i = 0; i < N; i++) {
		cin >> s;
		test_case[i] = new char[s.length() + 1]; //여기서 s.length+1을 써야함. 마지막에 NULL('\0')가 들어가야 하기 때문.
		size[i] = s.length();
		strcpy(test_case[i], s.c_str());
	}

	for (int i = 0; i < N; i++) {
		num_of_con = 0;
		for (int j = 0; j < size[i]; j++) { //test_case[i]는 s.length()+1 크기지만 size[i]그대로 써도 되는 이유: 문자 들어간 자리만 보면 되니까.
			if (j == size[i] - 1) {
				if (test_case[i][j] == 'O') {
					num_of_con++;
					score[i] += (1 + num_of_con) / 2 * num_of_con;
				}
				else {
					if (num_of_con != 0) {
						score[i] += (1 + num_of_con) / 2 * num_of_con;
					}
				}
			}
			else {
				if (test_case[i][j] == 'O') {
					num_of_con++;
				}
				else {
					score[i] += (1 + num_of_con) / 2 * num_of_con;
					num_of_con = 0;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << score[i] << '\n';
	}

	for (int i = 0; i < N; i++) {
		delete[] test_case[i];
	}
	delete[] test_case;
	delete[] score;
	delete[] size;

	return 0;
}
