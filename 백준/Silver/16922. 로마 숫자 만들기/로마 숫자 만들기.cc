#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int* arr = new int[50 * N]();
	int result = 0;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N - i + 1; j++) {
			for (int k = 0; k < N - i - j + 1; k++) {
				int l = N - i - j - k;
				int num = i + 5 * j + 10 * k + 50 * l;
				arr[num - 1] = 1;
			}
		}
	}
	for (int i = 0; i < N * 50; i++) {
		if (arr[i] != 0) {
			result++;
		}
	}
	cout << result;

	delete[] arr;
	return 0;
}