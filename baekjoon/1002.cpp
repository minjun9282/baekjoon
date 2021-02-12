#include <iostream>
#include <cmath>
using namespace std;

//distance는 int가 아닌데 int로 선언했기 때문에 계속 틀림.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int i = 0;
	int x_1, y_1, r_1, x_2, y_2, r_2;
	double distance;
	while (i < T) {
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		distance = sqrt(pow((x_1 - x_2), 2) + pow((y_1 - y_2), 2));

		if (distance == 0) {
			if (r_1 == r_2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			if ((distance > (double)r_1 + r_2)||(distance < abs(r_1 - r_2))) {
				cout << 0 << '\n';
			}
			else if ((distance == (double)r_1 + r_2) || (distance == abs(r_1 - r_2))) {
				cout << 1 << '\n';
			}
			else {
				cout << 2 << '\n';
			}
		}
		i++;
	}

	return 0;
}