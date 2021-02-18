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
	int temp, max, min, range;
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

	// 두번째 값 ~ 마지막 값 입력받기, 입력된 숫자의 총합과 최대, 최소값 계산하기.
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
				ary[length][0] = temp;
				result += temp;
				ary[length][1]++;
				if (temp > max) {
					max = temp;
				}
				if (temp < min) {
					min = temp;
				}
				length++;
				num++;
			}
		}
	}


	// 산술평균, 중앙값, 최빈값, 범위 결괏값 출력
	double mean = round(result / N);
	range = max - min;
	int mode_index = ary[0][1];

		// 최빈값 계산
	for (int i = 0; i < length; i++) {
		if()
	}
		// 중앙값 계산

	cout << mean << '\n';
	cout << "ㅁ" << '\n';
	cout << "ㅊ" << '\n';
	cout << range << '\n';

	//동적배열 할당 해제
	for (int i = 0; i < N; i++) {
		delete[] ary[i];
	}
	delete[] ary;


	return 0;
}