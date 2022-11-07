#include <iostream>
using namespace std;

int main() {
	int A, B, T;
	char comma;
	cin >> T;
	int i = 0;
	while (i < T) {
		cin >> A >> comma >> B;
		cout << A + B << '\n';
		i++;
	}

	return 0;
}