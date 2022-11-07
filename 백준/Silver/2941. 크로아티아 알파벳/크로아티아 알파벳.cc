#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	int result = 0;
	cin >> input;
	
	int i = 0;
	while (i < input.length()) {
		if (input[i] == 'c') {
			if ((input[i + 1] == '=') || (input[i + 1] == '-')) {
				result++;
				i += 2;
			}
			else {
				result++;
				i++;
			}
		}
		else if (input[i] == 'd') {
			if  (input[i + 1] == '-') {
				result++;
				i += 2;
			}
			else if(input[i+1] == 'z'){
				if (input[i + 2] == '=') {
					result++;
					i += 3;
				}
				else {
					result++;
					i++;
				}
			}
			else {
				result++;
				i++;
			}
		}
		else if (input[i] == 'l') {
			if (input[i + 1] == 'j') {
				result++;
				i += 2;
			}
			else {
				result++;
				i++;
			}
		}
		else if (input[i] == 'n') {
			if (input[i + 1] == 'j') {
				result++;
				i += 2;
			}
			else {
				result++;
				i++;
			}
		}
		else if (input[i] == 's') {
			if (input[i + 1] == '=') {
				result++;
				i += 2;
			}
			else {
				result++;
				i++;
			}
		}
		else if (input[i] == 'z') {
			if (input[i + 1] == '=') {
				result++;
				i += 2;
			}
			else {
				result++;
				i++;
			}
		}
		else {
			result++;
			i++;
		}
	}

	cout << result << '\n';

	return 0;
}