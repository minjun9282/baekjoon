#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 숫자 입력받기
	int N;
	cin >> N;

	//입력 받은 수의 각 자리 숫자를 배열에 넣기
	int digit = floor(log10(N)) + 1;
	int* ary = new int[digit];
	int num[10];
	fill_n(num, 10, 0);
	for (int i = 0; i < digit; i++) {
		num[N % 10]++;
		N = N / 10;
	}


	// 출력 및 동적할당 해제
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < num[i]; j++) {
			cout << i;
		}
	}

	delete[] ary;

	return 0;
}