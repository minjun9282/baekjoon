#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, w, h;
	cin >> x >> y;
	cin >> w >> h;

	int height_dif;
	int width_dif;
	int minimum;

	if ((w - x) <= x) {
		width_dif = w - x;
	}
	else {
		width_dif = x;
	}

	if ((h - y) <= y) {
		height_dif = h - y;
	}
	else {
		height_dif = y;
	}
	minimum = min(height_dif, width_dif);
	cout << minimum << '\n';

	return 0;
}