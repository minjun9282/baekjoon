#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B;
	int m;
	int decimal_num = 0;

	//1. �־��� ���ǿ� �°� 3�� �Է¹ޱ�
	cin >> A >> B;
	cin >> m;
	int* future_num = new int[m];
	for(int i = 0; i < m; i++) {
		cin >> future_num[i];
	}

	//2. A������ ����Ͽ� ���� ���ڸ� 10�������� ��ȯ
	for (int i = 0; i < m; i++) {
		decimal_num += future_num[m - 1 - i] * pow(A, i);
	}

	//3. 10�������� ��ȯ�� ���� �ٽ� B���� ���� ��ȯ
	int rem, quo=decimal_num;
	int count = 0;
	int i = 0;
	int arr[21] = {0,};
	while (true) {
		rem = quo % B;
		count++;
		arr[i] = rem;
		i++;
		quo = quo / B;
		if (quo < B) {
			arr[i] = quo;
			count++;
			break;
		}
	}
	for (int i = count - 1; i > -1; i--) {
		cout << arr[i] << " ";
	}

	delete[] future_num;

	return 0;
}