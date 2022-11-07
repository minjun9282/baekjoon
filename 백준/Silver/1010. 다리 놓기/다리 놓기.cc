#include <iostream>
using namespace std;

unsigned long long int comb(int M, int N);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;
	int i = 0;
	while (i < T) {
		cin >> N >> M;
		cout << comb(M, N) << '\n';
		i++;
	}

	return 0;
}


unsigned long long int comb(int M, int N) {
	unsigned long long int numerator = 1;
	unsigned long long int denominator = 1;
	int idx;
	if (N > M / 2) {
		idx = M - N;
	}
	else {
		idx = N;
	}
	int i = 0;
	while (i < idx) {
		numerator = numerator * (M - i);
		denominator = denominator * (idx - i);
		i++;
	}

	return numerator / denominator;
}