#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string* name = new string[N];
	cin >> name[0];
	bool inc = false;
	bool dec = false;
	bool maintain = true;
	for (int i = 1; i < N; i++) {
		cin >> name[i];
		if (name[i] < name[i - 1]) {
			dec = true;
		}
		else {
			inc = true;
		}
		if (dec == inc) {
			maintain = false;
		}
	}
	if (maintain == false) {
		cout << "NEITHER" << '\n';
	}
	else {
		if (dec == true) {
			cout << "DECREASING" << '\n';
		}
		else {
			cout << "INCREASING" << '\n';
		}
	}

	delete[] name;

	return 0;
}