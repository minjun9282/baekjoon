#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void multiple_thirty(string &num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string num;
	cin >> num;
	multiple_thirty(num);
	cout << num << '\n';

	return 0;
}

void multiple_thirty(string &num) {
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += (num[i] - '0');
	}
	if (sum % 3 != 0) {
		num = "-1";
	}
	else {
		sort(num.begin(), num.end(), greater<int>());
		if (num[num.size() - 1] != '0') {
			num = "-1";
		}
	}
}