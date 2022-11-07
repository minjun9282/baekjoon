#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;
	bool found = false;
	long i;
	if ((B > C) || (B==C)) {
		cout << -1 << '\n';
	}
	else {
		i = floor(long(A) / (C - B)) + 1;
		cout << int(i) << '\n';
	}

	return 0;
}