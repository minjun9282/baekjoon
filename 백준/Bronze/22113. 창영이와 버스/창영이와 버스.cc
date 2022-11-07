#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	int charge = 0;
	cin >> N >> M;
	int** arr = new int* [N];
	int* transfer = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> transfer[i];
	}
	for (int j = 0; j < N; j++) {
		arr[j] = new int[N];
	}
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			cin >> arr[j][k];
		}
	}
	for (int l = 0; l < M - 1; l++) {
		charge += arr[transfer[l] - 1][transfer[l + 1] - 1];
	}

	cout << charge << '\n';

	for (int j = 0; j < N; j++) {
		delete[] arr[j];
	}
	delete[] arr;
	delete[] transfer;

	return 0;
}