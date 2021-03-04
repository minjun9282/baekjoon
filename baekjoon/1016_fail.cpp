#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long min, max;
	cin >> min >> max;
	long long min_Squares = (long long)ceil(sqrt(min));
	long long max_Squares = (long long)floor(sqrt(max));

	cout << (max - min) - (max_Squares - min_Squares) << '\n';

	return 0;
}