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
		ary[i][1] = 0; // ary[i][0]�� �ش��ϴ� ���ڰ� ��� �ִ��� �Է��ϴ� ĭ.
	}


	// ù��° �� �Է¹ޱ�
	cin >> ary[0][0];
	result += ary[0][0];
	ary[0][1]++;
	length++;
	num++;
	min = ary[0][0];
	max = ary[0][0];

	// �ι�° �� ~ ������ �� �Է¹ޱ�, �Էµ� ������ ���հ� �ִ�, �ּҰ� ����ϱ�.
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


	// ������, �߾Ӱ�, �ֺ�, ���� �ᱣ�� ���
	double mean = round(result / N);
	range = max - min;
	int mode_index = ary[0][1];

		// �ֺ� ���
	for (int i = 0; i < length; i++) {
		if()
	}
		// �߾Ӱ� ���

	cout << mean << '\n';
	cout << "��" << '\n';
	cout << "��" << '\n';
	cout << range << '\n';

	//�����迭 �Ҵ� ����
	for (int i = 0; i < N; i++) {
		delete[] ary[i];
	}
	delete[] ary;


	return 0;
}