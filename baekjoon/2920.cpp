#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int scale[8];
	int i = 0;
	while (i < 8) {
		cin >> scale[i];
		i++;
	}

	bool mix = false;
	if (scale[0] == 1) {
		i = 2;
		while (i < 8) {
			if (scale[i] == scale[i - 1] + 1) {
				i++;
			}
			else {
				cout << "mixed" << '\n';
				mix = true;
				i = 8;
			}
		}
		if (mix == false) {
			cout << "ascending" << '\n';
		}
	}
	else if (scale[0] == 8) {
		i = 2;
		while (i < 8) {
			if (scale[i] == scale[i - 1] - 1) {
				i++;
			}
			else {
				cout << "mixed" << '\n';
				mix = true;
				i = 8;
			}
		}
		if (mix == false) {
			cout << "descending" << '\n';
		}
	}
	else {
		cout << "mixed" << '\n';
	}

	return 0;
}