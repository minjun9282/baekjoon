#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	int max;
	cin >> N >> M >> K;
	if (N >= 2 * M) {
		max = M;
	}
	else {
		max = N / 2;
	}
	N = N - max * 2;
	M = M - max;
	if (max == 0) {
		cout << 0 << '\n';
	}
	else if ((K <= M + N)) {
		cout << max << '\n';
	}
	else if ((K > M + N) && (max < 2)) {
		cout << 0 << '\n';
	}
	else {
		while (K > N + M) {
			max--;
			M += 1;
			N += 2;
			if (max == 0 && K > 0) {
				break;
			}

		}
		if (K > 0 && max == 0) {
			cout << 0 << '\n';
		}
		else {
			cout << max << '\n';
		}
	}


	return 0;
}