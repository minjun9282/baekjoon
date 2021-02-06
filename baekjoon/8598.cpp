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
		test_case[i] = new char[s.length() + 1]; //���⼭ s.length+1�� �����. �������� NULL('\0')�� ���� �ϱ� ����.
		size[i] = s.length();
		strcpy(test_case[i], s.c_str());
	}

	for (int i = 0; i < N; i++) {
		num_of_con = 0;
		for (int j = 0; j < size[i]; j++) { //test_case[i]�� s.length()+1 ũ������ size[i]�״�� �ᵵ �Ǵ� ����: ���� �� �ڸ��� ���� �Ǵϱ�.
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
