#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	string input;
	string s;
	cin >> num;
	cin >> input;
	int result = 0;
	for (int i = 0; i < num; i++) {
		s = input[i];
		result += stoi(s); //stoi(inut[i])�� �ٷ� ���� �� ����.
	}
	cout << result << '\n';
	
	return 0;
}