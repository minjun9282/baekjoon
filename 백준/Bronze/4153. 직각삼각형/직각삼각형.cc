#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	int num[3];
	int max_value;
	int min_value;
	int median;

	while (true) {
		cin >> a >> b >> c;
		num[0] = a;
		num[1] = b;
		num[2] = c;
		if ((a + b + c) == 0) {
			break;
		}
		else {
			max_value = max(a, b);
			max_value = max(max_value, c);
			min_value = min(a, b);
			min_value = min(min_value, c);
			for (int i = 0; i < 3; i++) {
				if ((num[i] != max_value) && (num[i] != min_value)) {
					median = num[i];
				}
			}
		}
		if ((pow(max_value, 2) == pow(median, 2) + pow(min_value, 2)) && (min_value != 0)) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << "\n";
		}
	}
	return 0;
}