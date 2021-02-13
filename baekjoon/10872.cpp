#include <iostream>
using namespace std;

int factorial(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << factorial(N) << '\n';

	return 0;
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}