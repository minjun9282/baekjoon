#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	float A, I;
	cin >> A >> I;
	cout << A * (I - 1) + 1<< '\n';

	return 0;
}