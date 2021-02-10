#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N;
	cin >> M;
	cin >> N;
	int min = 0;
	int sum = 0;
	int* arr = new int[N - M + 1];
	for (int i = 0; i < N - M + 1; i++) {
		arr[i] = M + i;
	}
	for (int i = 0; i < N - M + 1; i++) {
		if (arr[i] >= 2) {
			int j = 2;
			bool prime = true;
			while (j < arr[i] - 1) {
				if ((arr[i] % j == 0)&&(arr[i] != j)) {
					prime = false;
					break;
				}
				else{
					j++;
				}
			}
			if (prime == true) {
				sum += arr[i];
				if (min == 0) {
					min = arr[i];
				}
			}
		}
	}
	if (min != 0) {
		cout << sum << '\n';
		cout << min << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	delete[] arr;
	return 0;
}