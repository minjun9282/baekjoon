#include <iostream>
#include <cmath>
using namespace std;

int sum_Decomposition(int N);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int constructor;
	cin >> N;

	cout << sum_Decomposition(N) << '\n';

	return 0;
}

int sum_Decomposition(int N) {
	bool found = false;
	int ciphers = (int)floor(log10(N)) + 1;
	int minimum = N - 9 * (ciphers - 1) - (int)(N / pow(10, ciphers - 1));

	int sum = 0;
	int i = 0;
	int decomposition = minimum;

	while (decomposition < N) {
		minimum = decomposition;
		sum += minimum;
		while (i < ciphers) {
			sum += minimum % 10;
			minimum = (int)(minimum / 10);
			i++;
		}
		if (sum == N) {
			found = true;
			break;
		}
		else {
			i = 0;
			sum = 0;
			decomposition++;
		}
	}

	if (found == true)
		return decomposition;
	else
		return 0;
}