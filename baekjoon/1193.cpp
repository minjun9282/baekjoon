#include <iostream>
using namespace std;

void find_x(int input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int input;
	cin >> input;
	find_x(input);

	return 0;
}

void find_x(int input) {
	bool found = false;
	int i = 1;
	if (input == 1) {
		cout << "1/1" << '\n';
	}
	else {
		while (!found) {
			if ((i * (i + 1) / 2 < input) && (input <= (i + 1) * (i + 2) / 2)) {
				found = true;
			}
			else {
				i++;
			}
		}
		if ((i % 2) == 1) {
			int k = input - (i * (i + 1) / 2) - 1;
			int numerator = 1;
			int denominator = i + 1;
			while (k != 0) {
				numerator++;
				denominator--;
				k--;
			}
			cout << numerator << "/" << denominator << '\n';
		}
		else {
			int k = input - (i * (i + 1) / 2) - 1;
			int numerator = i + 1;
			int denominator = 1;
			while (k != 0) {
				numerator--;
				denominator++;
				k--;
			}
			cout << numerator << "/" << denominator << '\n';
		}
	}
}