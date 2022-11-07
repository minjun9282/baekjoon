#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;

	// 1. 테스트 케이스의 개수 T 입력받기.
	cin >> T;

	// 2.각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 구분해서 출력하기.
	int i = 0;
	int test_case;

	int  num_zero[41]; num_zero[0] = 1; num_zero[1] = 0; num_zero[2] = 1;
	int  num_one[41]; num_one[0] = 0; num_one[1] = 1; num_one[2] = 1;

	for (int i = 3; i < 41; i++) {
		num_zero[i] = num_zero[i - 1] + num_zero[i - 2];
		num_one[i] = num_one[i - 1] + num_one[i - 2];
	}

	while (i < T) {
		cin >> test_case;
		cout << num_zero[test_case] << " " << num_one[test_case] << '\n';
		i++;
	}

	return 0;
}