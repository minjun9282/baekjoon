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
//	const char* c = input.c_str(); // �� ��쿡�� char*���� �����Ͽ� ����� ���� ����.
	strcpy(ch1, input.c_str());
	char* ptr = strtok(ch1, " ");
	int result = 0;
	while (ptr != NULL) {
		ptr = strtok(NULL, " "); // ù��° �Ű������δ� Ž���� ���ڿ�, �ι�° �Ű������δ� �����ڸ� �����.
		result++;
	}
	cout << result << "\n";

	return 0;
}