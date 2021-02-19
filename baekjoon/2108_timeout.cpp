#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	
	int length = 0;
	int num = 0;
	double result = 0;
	int temp, max, min, range, index;
	bool found = false;

	int** ary = new int*[N];
	for (int i = 0; i < N; i++) {
		ary[i] = new int[2];
		ary[i][1] = 0; // ary[i][0]에 해당하는 숫자가 몇개가 있는지 입력하는 칸.
	}


	// 첫번째 값 입력받기
	cin >> ary[0][0];
	result += ary[0][0];
	ary[0][1]++;
	length++;
	num++;
	min = ary[0][0];
	max = ary[0][0];

	// 두번째 값 ~ 마지막 값 입력받기, 입력된 숫자의 총합과 최댓값 및 최솟값 계산하기.
	while (true) {
		if (num == N) {
			break;
		}
		else {
			cin >> temp;
			found = false;
			for (int j = 0; j < length; j++) {
				if (temp == ary[j][0]) {
					result += temp;
					ary[j][1]++;
					if (temp > max) {
						max = temp;
					}
					if (temp < min) {
						min = temp;
					}
					found = true;
					num++;
				}
			}
			if (found != true) {
				if (temp > ary[length - 1][0]) {
					ary[length][0] = temp;
					ary[length][1]++;
				}
				else {
					for (int k = length-1; k > -1; k--) {
						if (temp < ary[k][0]) {
							index = k;
						}
					}
					for (int m = length; m > index; m--) {
						ary[m][0] = ary[m - 1][0];
						ary[m][1] = ary[m - 1][1];
					}
					ary[index][0] = temp;
					ary[index][1] = 1;
				}
				if (temp > max) {
					max = temp;
				}
				if (temp < min) {
					min = temp;
				}
				result += temp;
				length++;
				num++;
			}
		}
	}


	// 산술평균, 중앙값, 최빈값, 범위 결괏값 출력
	double mean = round(result / N);
	range = max - min;
	

		// 최빈값 계산
	int mode;
	int max_frequency = ary[0][1];
	int mode_index = 0;
	int num_max_frequency = 1;
	for (int i = 1; i < length; i++) {
		if (ary[i][1] > max_frequency) {
			mode_index = i;
			num_max_frequency = 1;
			max_frequency = ary[i][1];
		}
		else if (ary[i][1] == max_frequency) {
			num_max_frequency++;
		}
	}
	if (num_max_frequency > 1) {
		int h = mode_index + 1;
		while (true) {
			if (ary[h][1] == ary[mode_index][1]) {
				mode_index = h;
				break;
			}
			h++;
		}
	}
	mode = ary[mode_index][0];

		// 중앙값 계산
	int median = N / 2 + 1;
	int sum_number = 0;
	for (int i = 0; i < length; i++) {
		sum_number += ary[i][1];
		if (sum_number == median) {
			index = i;
		}
		else if ((median > sum_number) && (median <= sum_number + ary[i + 1][1])) {
			index = i+1;
		}
	}
	median = ary[index][0];

	cout << mean << '\n';
	cout <<  median << '\n';
	cout << mode << '\n';
	cout << range << '\n';

	//동적배열 할당 해제
	for (int i = 0; i < N; i++) {
		delete[] ary[i];
	}
	delete[] ary;

	return 0;
}
