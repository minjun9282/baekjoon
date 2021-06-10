#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int S;
	cin >> S;
	long long int result = 0;
	long long int i = 1;
	while (true) {
		result += i;
		if ((result <= S) && (result + i + 1 > S)) {
			break;
		}
		else {
			i++;
		}
	}
	cout << i << '\n';

	return 0;
}