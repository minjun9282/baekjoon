#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int alphabet[26];
	fill_n(alphabet, 26, -1);
	string input;
	cin >> input;
	int index;
	for (int i = 0; i < input.length(); i++) {
		index = int(input[i]) - int('a');
		if (alphabet[index] == -1) {
			alphabet[index] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}

	return 0;
}