#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int result = 0;
	int mult_5 = N / 5;
	int mult_25 = N / 25;
	int mult_125 = N / 125;
	result += (mult_125 * 3 + (mult_25 - mult_125) * 2 + (mult_5 - mult_25));

	cout << result << '\n';

	return 0;
}