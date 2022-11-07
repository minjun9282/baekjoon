#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	bool increase = true;
	bool decrease= false;
	bool mountain = true;
	int temp, prev = 0;
	int changed = 0;
	int i = 0;
	while (i < N) {
		cin >> temp;
		if (temp > prev) {
			prev = temp;
			if (increase == false && decrease == true) {
				changed++;
			}
		}
		else if (temp < prev) {
			prev = temp;
			if (changed == 0) {
				increase = false;
				decrease = true;
				changed++;
			}
		}
		else {
			mountain = false;
			break;
		}

		if (changed > 1) {
			mountain = false;
			break;
		}
		i++;
	}

	if (mountain == true) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
	

	return 0;
}