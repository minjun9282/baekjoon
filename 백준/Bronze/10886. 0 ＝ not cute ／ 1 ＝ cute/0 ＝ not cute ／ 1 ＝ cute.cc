#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int result_0 = 0;
	int result_1 = 0;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			result_0++;
		}
		else {
			result_1++;
		}
	}

	if (result_0 > result_1) {
		cout << "Junhee is not cute!" << '\n';
	}
	else {
		cout << "Junhee is cute!" << '\n';
	}

	return 0;
}