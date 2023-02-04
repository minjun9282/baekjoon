#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string number_plate;
	cin >> number_plate;
	int result;
	int alph = 26;
	int num = 10;
	if (number_plate[0] == 'c') {
		result = alph;
	}
	else {
		result = num;
	}
	int i = 1;
	while (i < number_plate.size()) {
		if (number_plate[i] != number_plate[i - 1]) {
			num = 10;
			alph = 26;
			if (number_plate[i - 1] == 'c') {
				result *= num;
			}
			else {
				result *= alph;
			}
		}
		else {
			if (number_plate[i - 1] == 'c') {
				result *= alph - 1;
			}
			else {
				result *= num - 1;
			}
		}
		i++;
	}
	cout << result << '\n';


	return 0;
}