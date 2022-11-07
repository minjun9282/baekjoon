#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[5] = { 0, };
	int i = 0;
	int j = 0;
	int a, b, c, d;
	while (i < 5) {
		cin >> a >> b >> c >> d;
		arr[i] += (a + b + c + d);
		i++;
	}
	int max_turn = 0;
	int max = arr[0];
	for (int j = 1; j < 5; j++) {
		if (arr[j] > max) {
			max = arr[j];
			max_turn = j;
		}
	}

	cout << max_turn + 1 << " " << max << '\n';

	return 0;
}