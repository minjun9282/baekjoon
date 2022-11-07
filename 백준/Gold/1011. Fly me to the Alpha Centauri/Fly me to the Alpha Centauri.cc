#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int i = 0;
	int result = 0;
	int x, y;
	int min;
	while (i < T) {
		cin >> x >> y;
		min = floor(sqrt(y - x));
		if ((y - x) == pow(min, 2)) {
			result = 2 * min - 1;
		}
		else {
			if ((y - x) <= pow(min, 2) + min) {
				result = 2 * min;
			}
			else {
				result = 2 * min + 1;
			}
		}

		cout << result << '\n';
		i++;
	}
	return 0;
}