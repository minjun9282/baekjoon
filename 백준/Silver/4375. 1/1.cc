#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int i = 0;
	int rem;
	long long int sum = 1;

	while (cin >> n) {
		while (true) {
			rem = sum % n;
			if (rem == 0) {
				cout << i + 1 << '\n';
				i = 0;
				sum = 1;
				break;
			}
			else {
				i++;
				sum = (rem * 10 + 1) % n;
			}
		}
	}

	return 0;
}