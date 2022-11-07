#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[9];
	int sorted_arr[9];
	int i = 0;
	int result = 0;
	while (i < 9) {
		cin >> arr[i];
		result += arr[i];
		i++;
	}
	int min, min_index;
	for (int i = 0; i < 9; i++) {
		min = arr[0];
		min_index = 0;
		for (int j = 1; j < 9; j++) {
			if (arr[j] < min) {
				min = arr[j];
				min_index = j;
			}
		}
		sorted_arr[i] = min;
		arr[min_index] = 100;
	}

	int diff = result - 100;
	int index_i, index_j;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sorted_arr[i] + sorted_arr[j] == diff) {
				index_i = i;
				index_j = j;
			}
		}
	}
	for (int k = 0; k < 9; k++)
	{
		if ((k != index_i) && (k != index_j))
			cout << sorted_arr[k] << '\n';
	}

	return 0;
}