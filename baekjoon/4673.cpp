#include <iostream>
#include <cmath>
using namespace std;

int sum_of_digit(int n);
bool self_number(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i = 1;
	while(i < 10001) {
		if (self_number(i) == true) {
			cout << i << '\n';
			i++;
		}
		else {
			i++;
		}
	}


	return 0;
}

int sum_of_digit(int n) {
	int input = n;
	int result = 0;
	int index = floor(log10(n));
	while (index > -1) {
		result += input / int(pow(10,index));
		input = input % int(pow(10, index));
		index--;
	}
	result += n;
	return result;
}

bool self_number(int n) {
	int index = floor(log10(n)) + 1; // 두자리수면 2, 한자리수면 1이 나옴.
	int minimum = n - index * 9; // 여기서 minimum을 어떻게 설정하느냐에 따라 연산속도에서 차이발생함.
	int i;
	if (index == 1) {
		i = 1;
	}
	else {
		i = minimum;
	}
	while (i < n) {
		if (sum_of_digit(i) == n) {
			return false;
		}
		else {
			i++;
		}
	}
	return true;
}
