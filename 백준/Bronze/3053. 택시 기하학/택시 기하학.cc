#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(6);

	double pi = M_PI;
	int R;
	cin >> R;
	
	cout << R * R * pi << '\n';
	cout << 2 * R * R << '\n';

	return 0;
}