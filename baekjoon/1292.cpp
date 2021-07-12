#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B;
	cin >> A >> B;
	int* arr = new int[B];
	int i = 0;
	int j = 1;
	int k = 0;
	while (i < B) {
		while (k < j) {
			arr[i] = j;
			k++;
			i++;
			if (i == B)
				break;
		}
		j += 1;
		k = 0;
	}
	int result = 0;
	for (int l = A - 1; l < B; l++) {
		result +=  arr[l];
	}
	cout << result << "\n";

	delete[] arr;

	return 0;
}