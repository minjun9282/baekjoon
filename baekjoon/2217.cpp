#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int* arr = new int[N];
	int i = 0;
	while (i < N) {
		cin >> arr[i];
		i++;
	}
	sort(arr, arr + N);
	int result = arr[0] * N;
	for (int i = 1; i < N; i++) {
		if (result < arr[i] * (N - i)) {
			result = arr[i] * (N - i);
		}
	}

	cout << result;

	return 0;
}