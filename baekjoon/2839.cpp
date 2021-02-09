#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	if ((N == 1) || (N == 2)) {
		cout << -1 << '\n';
	}
	else if ((N == 4) || (N == 7)) {
		cout << -1 << '\n';
	}
	else if ((N == 3) || (N == 5)) {
		cout << 1 << '\n';
	}
	else {
		int result = 0;
		int quo = N / 5;
		int rem = N % 5;
		if (rem % 3 == 0) {
			result = quo + rem / 3;
		}
		else {
			while (true) {
				quo--;
				rem += 5;
				if (rem % 3 == 0) {
					result += (quo + rem / 3);
					break;
				}

			}
		}
		cout << result << '\n';
	}

	return 0;
}