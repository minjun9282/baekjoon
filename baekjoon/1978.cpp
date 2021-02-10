#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 2) {
			bool prime = true;
			int j = 2;
			while (j < arr[i] - 1) {
				if ((arr[i] % j == 0)&&(arr[i] != j)) {
					prime = false;
					break;
				}
				j++;
			}
			if (prime == true) {
				result++;
			}
		}
	}
	cout << result << '\n';

	delete[] arr;

	return 0;
}