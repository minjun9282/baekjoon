#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string S;
	cin >> S;
	int string_zero = 0;
	int string_one = 0;
	if (S[0] == '0') {
		string_zero += 1;
		for (int i = 0; i < S.size() - 1; i++) {
			if (S[i] != S[i + 1]) {
				if (S[i + 1] == '1') {
					string_one += 1;
				}
				else {
					string_zero += 1;
				}
			}
		}
	}
	else {
		string_one += 1;
		for (int i = 0; i < S.size() - 1; i++) {
			if (S[i] != S[i + 1]) {
				if (S[i + 1] == '0') {
					string_zero += 1;
				}
				else {
					string_one += 1;
				}
			}
		}
	}

	if (string_zero < string_one) {
		cout << string_zero << '\n';
	}
	else {
		cout << string_one << '\n';
	}


	return 0;
}