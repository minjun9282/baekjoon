#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C, D;
	cin >> A >> B >> C;
	cin >> D;
	int hour, min, sec;
	hour = D / 3600;
	min = (D % 3600) / 60;
	sec = (D % 3600) % 60;

	A = (A + hour + (B + min + ((C + sec) / 60)) / 60) % 24;
	B = (B + min + ((C + sec) / 60)) % 60;
	C = (C + sec) % 60;
	cout << A << " " << B << " " << C << '\n';

	return 0;
}