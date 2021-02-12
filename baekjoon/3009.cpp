#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x[4]; 
	int y[4];
	int x_coordinate, y_coordinate;
	int i = 0;
	while (i < 3) {
		cin >> x_coordinate >> y_coordinate;
		x[i] = x_coordinate;
		y[i] = y_coordinate;
		i++;
	}
	if (x[0] == x[1]) {
		x[3] = x[2];
	}
	else if (x[0] == x[2]) {
		x[3] = x[1];
	}
	else {
		x[3] = x[0];
	}

	if (y[0] == y[1]) {
		y[3] = y[2];
	}
	else if (y[0] == y[2]) {
		y[3] = y[1];
	}
	else {
		y[3] = y[0];
	}
	cout << x[3] << " " << y[3] << '\n';

	return 0;
}