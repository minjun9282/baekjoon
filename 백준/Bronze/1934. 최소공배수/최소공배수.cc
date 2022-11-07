#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, A, B;
	cin >> T;
	int i = 0;
	int* arr = new int[T];

	while (i < T) {
		cin >> A >> B;
		arr[i] = gcd(A, B) * (A / gcd(A,B)) * (B / gcd(A,B));
		i++;
	}
	for (int i = 0; i < T; i++) {
		cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;
}

int gcd(int a, int b) {
	int greater = (a < b) ? b : a;
	int smaller = (a < b) ? a : b;
	int gcd_value;
	int rem;
	while (true) {
		rem = greater % smaller;
		if (rem == 0) {
			gcd_value = smaller;
			break;
		}
		else {
			greater = smaller;
			smaller = rem;
		}
	}
	return gcd_value;
}