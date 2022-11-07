#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, H, W, N;
	cin >> T;
	int i = 0;
	while (i < T) {
		cin >> H >> W >> N;
		int floor;
		int ordinal = 0;
		bool found = false;
		while (!found) {
			if ((ordinal * H < N) && (N <= (ordinal + 1) * H)) {
				found = true;
			}
			else {
				ordinal++;
			}
		}
		floor = N - H * ordinal;
		if (ordinal + 1 < 10) {
			cout << floor << 0 << (ordinal + 1) << '\n';
		}
		else {
			cout << floor << (ordinal + 1) << '\n';
		}
		i++;
	}

	return 0;
}