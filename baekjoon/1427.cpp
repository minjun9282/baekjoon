#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// ���� �Է¹ޱ�
	int N;
	cin >> N;

	//�Է� ���� ���� �� �ڸ� ���ڸ� �迭�� �ֱ�
	int digit = floor(log10(N)) + 1;
	int* ary = new int[digit];
	int num[10];
	fill_n(num, 10, 0);
	for (int i = 0; i < digit; i++) {
		num[N % 10]++;
		N = N / 10;
	}


	// ��� �� �����Ҵ� ����
	for (int i = 9; i > -1; i--) {
		for (int j = 0; j < num[i]; j++) {
			cout << i;
		}
	}

	delete[] ary;

	return 0;
}