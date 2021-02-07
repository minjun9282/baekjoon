#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int time(char input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	cin >> input;
	char ch[16];
	strcpy(ch, input.c_str());

	int result = 0;
	for (int i = 0; i < input.length(); i++) {
		result += time(ch[i]);
	}

	cout << result << '\n';

	return 0;
}

int time(char input) {
	if ((int(input) > 64) && (int(input) < 68)) {
		return 3;
	}
	else if ((int(input) > 67) && (int(input) < 71)) {
		return 4;
	}
	else if ((int(input) > 70) && (int(input) < 74)) {
		return 5;
	}
	else if ((int(input) > 73) && (int(input) < 77)) {
		return 6;
	}
	else if ((int(input) > 76) && (int(input) < 80)) {
		return 7;
	}
	else if ((int(input) > 79) && (int(input) < 84)) {
		return 8;
	}
	else if ((int(input) > 83) && (int(input) < 87)) {
		return 9;
	}
	else{
		return 10;
	}
}