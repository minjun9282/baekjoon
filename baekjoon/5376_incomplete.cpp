#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// long long int 정도로 커버가 불가능한, 괄호 안에 매우 긴 숫자가 들어올 경우를 생각해야 함.


int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	string* array = new string[T];
	bool rat_num = false;
	long long int numerator, denominator;
	long long int fixed, circular;
	long long int start_idx, left_par_idx, right_par_idx;
	long long int gcd_val;
	for (int i = 0; i < T; i++) {
		cin >> array[i];
		if (array[i].find('(') == string::npos) {
			rat_num = true;
		}
		else {
			rat_num = false;
		}
		if (rat_num == true) {
			start_idx = array[i].find('.');
			numerator = stol(array[i].substr(start_idx + 1, array[i].length() - start_idx - 1));
			denominator = pow(10, array[i].length() - start_idx - 1);
			gcd_val = gcd(denominator, numerator);
			array[i] = to_string(numerator / gcd_val) + "/" + to_string(denominator / gcd_val);
		}
		else {
			start_idx = array[i].find('.');
			left_par_idx = array[i].find('(');
			right_par_idx = array[i].find(')');
			if (start_idx + 1 == left_par_idx) {
				circular = stol(array[i].substr(left_par_idx + 1, right_par_idx - left_par_idx - 1));
				denominator = pow(10, right_par_idx - left_par_idx - 1) - 1;
				gcd_val = gcd(denominator, circular);
				array[i] = to_string(circular / gcd_val) + "/" + to_string(denominator / gcd_val);
			}
			else {
				fixed = stol(array[i].substr(start_idx + 1, left_par_idx - start_idx - 1));
				circular = stol(array[i].substr(left_par_idx + 1, right_par_idx - left_par_idx - 1));
				denominator = pow(10, left_par_idx - start_idx - 1) * (pow(10, right_par_idx - left_par_idx - 1) - 1);
				numerator = pow(10, right_par_idx - left_par_idx - 1) * fixed + circular - fixed;
				gcd_val = gcd(denominator, numerator);
				array[i] = to_string(numerator / gcd_val) + "/" + to_string(denominator / gcd_val);
			}
		}	
	}

	for (int i = 0; i < T; i++) {
		cout << array[i] << '\n';
	}

	return 0;
}

int gcd(int a, int b) {
	int n;

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
