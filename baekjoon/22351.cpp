#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string S;
	cin >> S;
	int ans_A, ans_B;
	bool found = false;
	if (S.length() == 1) {
		ans_A = stoi(S);
		ans_B = ans_A;
		cout << ans_A << " " << ans_B << '\n';
	}
	else if (S.length() == 2) {
		if (stoi(S.substr(0, 1)) + 1 == stoi(S.substr(1, 1))){
			ans_A = stoi(S.substr(0, 1));
			ans_B = stoi(S.substr(1, 1));
			cout << ans_A << " " << ans_B << '\n';
		}
		else {
			ans_A = stoi(S);
			ans_B = ans_A;
			cout << ans_A << " " << ans_B << '\n';
		}
	}
	else {
		int A[3];
		int B[3];
		for (int i = 0; i < 3; i++) {
			A[i] = stoi(S.substr(0, i + 1));
			B[i] = stoi(S.substr(S.length() - i - 1, i + 1));
		}
		for (int i = 0; i < 3; i++) {
			for (int j = i; j < 3; j++) {
				if ((A[i] <= B[j]) && (found == false)) {
					if (i + 1 == j) {
						if (S.length() == ((pow(10, i + 1) - A[i]) * j + (B[j] - pow(10, i + 1) + 1) * (j + 1))) {
							ans_A = A[i];
							ans_B = B[j];
							found = true;
						}
					}
					else if (i == j){
						if (S.length() == (B[j] - A[i] + 1) * (i + 1)) {
							ans_A = A[i];
							ans_B = B[j];
							found = true;
						}
					}
					else {
						if (found == false) {
							ans_A = A[i];
							ans_B = B[j];
						}
					}
				}
			}
		}
		cout << ans_A << " " << ans_B << '\n';
	}
	
	return 0;
}