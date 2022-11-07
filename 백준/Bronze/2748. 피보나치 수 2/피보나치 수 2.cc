#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long int* arr = new long long[n+1];
	arr[0] = 0;
	arr[1] = 1;
	int i = 2;
	while (i < n+1) {
		arr[i] = arr[i - 1] + arr[i - 2];
		i++;
	}
	cout << arr[n] << '\n';
	delete[] arr;

	return 0;
}