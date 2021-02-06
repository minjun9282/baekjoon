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
		result += stoi(s); //stoi(inut[i])는 바로 받을 수 없음.
	}
	cout << result << '\n';
	
	return 0;
}