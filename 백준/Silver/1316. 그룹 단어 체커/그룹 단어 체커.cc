#include <iostream>
#include <string>
using namespace std;

bool group_checker(string input);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int number;
	cin >> number;
	string* word = new string[number];

	for (int i = 0; i < number; i++) {
		cin >> word[i];
	}
	int result = 0;
	for (int i = 0; i < number; i++) {
		if (group_checker(word[i]) == true) {
			result++;
		}
	}
	cout << result << '\n';

	delete[] word;

	return 0;
}

bool group_checker(string input) {
	bool group = true;
	int number = input.length();
	if (number == 1) {
		return group;
	}
	else {
		string* alphabet = new string[number];
		alphabet[0] = input[0];
		int k = 1;
		for (int i = 1; i < number; i++) {
			for (int j = i - 1; j < i; j++) {
				if (input[i] != input[j]) {
					alphabet[k] = input[i];
					k++;
				}
			}
		}
		for (int h = 0; h < k; h++) {
			for (int g = h + 1; g < k; g++) {
				if (alphabet[h] == alphabet[g])
					group = false;
			}
		}

		delete[] alphabet;
		return group;
	}
}