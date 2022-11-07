#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	if (((N - 1) % 4 == 0) || ((N - 3) % 4 == 0)) {
		cout << "SK" << '\n';
	}
	else {
		cout << "CY" << '\n';
	}


	return 0;
}