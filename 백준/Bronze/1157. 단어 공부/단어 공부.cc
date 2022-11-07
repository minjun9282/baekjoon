#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int alphabet[26];
	fill_n(alphabet, 26, 0);
	string input;
	cin >> input;

	int index;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] > 96) {
			index = int(input[i]) - 32 - int('A');
		}
		else {
			index = int(input[i]) - int('A');
		}
		alphabet[index] += 1;
		index = 0;
	}

	int max_index = 0;
	int max_num = 0;
	int dup = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max_num) {
			max_index = i;
			max_num = alphabet[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max_num)
			dup += 1;
	}

	if (dup != 1) {
		cout << '?' << '\n';
	}
	else {
		cout << char(max_index + int('A')) << '\n';
	}

	return 0;
}