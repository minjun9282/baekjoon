#include <iostream>
using namespace std;

int room(int input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int out;
	cin >> out;
	cout << room(out) << '\n';

	return 0;
}

int room(int input) {
	bool found = false;
	int i = 0;
	if (input == 1)
		return 1;
	else {
		while (!found) {
			if ((1 + 3 * i * (1 + i) < input) && (input <= 1 + 3 * (i + 1) * (i + 2))) {
				found = true;
			}
			else {
				i++;
			}
		}
		return i + 2;
	}
}