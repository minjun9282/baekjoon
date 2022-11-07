#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C;
	int num_A, num_B, num_C;
	A = 300; num_A = 0;
	B = 60; num_B = 0;
	C = 10; num_C = 0;
	int T;
	cin >> T;
	bool finished = false;
	while (!finished) {
		if (T >= 300) {
			T = T - 300;
			num_A++;
		}
		else if ((T < 300) && (T >= 60)) {
			T = T - 60;
			num_B++;
		}
		else if ((T < 60) && (T >= 10)) {
			T = T - 10;
			num_C++;
		}
		else if (T == 0) {
			finished = true;
		}
		else {
			break;
		}
	}
	if (finished == true) {
		cout << num_A << " " << num_B << " " << num_C << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}