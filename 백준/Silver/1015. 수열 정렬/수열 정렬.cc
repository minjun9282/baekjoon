#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	int** arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[2];
		cin >> arr[i][0];
		arr[i][1] = -1;
	}
	int* des = new int[N];

	int min, min_idx;
	int i = 0;
	while (i < N) {
		min = 1001;
		for (int k = 0; k < N; k++) {
			if ((arr[k][0] < min) && (arr[k][1] == -1)) {
				min = arr[k][0];
				min_idx = k;
			}
		}
		arr[min_idx][1] = i;
		i++;
	}

	for (int j = 0; j < N; j++) {
		cout << arr[j][1] << " ";
		delete[] arr[j];
	}
	delete[] arr;
	delete[] des;

	return 0;
}