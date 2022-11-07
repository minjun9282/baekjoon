#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B;
	int m;
	int decimal_num = 0;

	//1. 주어진 조건에 맞게 3줄 입력받기
	cin >> A >> B;
	cin >> m;
	int* future_num = new int[m];
	for(int i = 0; i < m; i++) {
		cin >> future_num[i];
	}

	//2. A진법을 사용하여 만든 숫자를 10진법으로 전환
	for (int i = 0; i < m; i++) {
		decimal_num += future_num[m - 1 - i] * pow(A, i);
	}

	//3. 10진법으로 전환한 수를 다시 B진법 수로 전환
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