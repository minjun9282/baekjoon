#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int binary_sys[7] = {0,};
	int X;
	cin >> X;
	int rem, count_one = 0;
	int i = 0;

	while (X != 0) {
		rem = X % 2;
		X = X / 2;
		binary_sys[i] = rem;
		i++;
	}

	for (int j = 0; j < 7; j++) {
		count_one += binary_sys[j];
	}

	cout << count_one << '\n';

	return 0;
}