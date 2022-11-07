#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input;
	getline(cin, input);
	char ch1[1000000];
	strcpy(ch1, input.c_str());
	char* ptr = strtok(ch1, " ");
	int result = 0;
	while (ptr != NULL) {
		ptr = strtok(NULL, " ");
		result++;
	}
	cout << result << "\n";

	return 0;
}