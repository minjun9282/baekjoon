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
//	const char* c = input.c_str(); // 이 경우에는 char*형을 수정하여 사용할 수는 없음.
	strcpy(ch1, input.c_str());
	char* ptr = strtok(ch1, " ");
	int result = 0;
	while (ptr != NULL) {
		ptr = strtok(NULL, " "); // 첫번째 매개변수로는 탐색할 문자열, 두번째 매개변수로는 구분자를 사용함.
		result++;
	}
	cout << result << "\n";

	return 0;
}