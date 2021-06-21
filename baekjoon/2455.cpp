#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int boarding = 0;
	int departing = 0;
	cin >> departing >> boarding;
	int max = boarding;
	int result = boarding;
	for (int i = 0; i < 3; i++) {
		cin >> departing >> boarding;
		result += (boarding - departing);
		if (result > max) {
			max = result;
		}
	}
	cout << max << '\n';

	return 0;
}