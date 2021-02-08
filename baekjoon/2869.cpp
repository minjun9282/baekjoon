#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A, B, V;
	cin >> A >> B >> V;
	if (A == V) {
		cout << 1 << '\n';
	}
	else {
		int i = ceil(double(V - A) / (A - B));
		cout << i + 1 << '\n';
	}
	return 0;
}