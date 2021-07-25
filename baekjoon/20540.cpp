#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char arr[4];
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	if (arr[0] == 'E') {
		cout << 'I';
	}
	else {
		cout << 'E';
	}
	if (arr[1] == 'S') {
		cout << 'N';
	}
	else {
		cout << 'S';
	}
	if (arr[2] == 'T') {
		cout << 'F';
	}
	else {
		cout << 'T';
	}
	if (arr[3] == 'J') {
		cout << 'P';
	}
	else {
		cout << 'J';
	}

	return 0;
}