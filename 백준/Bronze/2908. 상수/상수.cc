#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string A, B;
	cin >> A >> B;
	if (A[2] > B[2]) {
		cout << A[2] << A[1] << A[0] << '\n';
	}
	else if (A[2] == B[2]) {
		if (A[1] > B[1]) {
			cout << A[2] << A[1] << A[0] << '\n';
		}
		else if (A[1] == B[1]) {
			if (A[0] > B[0]) {
				cout << A[2] << A[1] << A[0] << '\n';
			}
			else {
				cout << B[2] << B[1] << B[0] << '\n';
			}
		}
		else {
			cout << B[2] << B[1] << B[0] << '\n';
		}
	}
	else {
		cout << B[2] << B[1] << B[0] << '\n';
	}
	return 0;
}