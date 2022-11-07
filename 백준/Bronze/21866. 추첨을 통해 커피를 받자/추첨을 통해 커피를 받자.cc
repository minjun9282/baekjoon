#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = 0;
	int i = 0;
	int max = 100;
	int temp;
	bool coffee = false;
	bool hacker = false;
	while (i < 9) {
		cin >> temp;
		sum += temp;
		if (temp > max) {
			hacker = true;
			break;
		}
		i++;
		if (i % 2 == 0) {
			max += 100;
		}
	}

	if (hacker == true) {
		cout << "hacker" << '\n';
	}
	else if ((hacker == false) && (sum < 100)) {
		cout << "none" << '\n';
	} 
	else {
		cout << "draw" << '\n';
	}

	return 0;
}