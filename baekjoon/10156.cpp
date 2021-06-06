#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int K, N, M;
	cin >> K >> N >> M;
	int change;
	if (K * N > M) {
		cout << K * N - M << '\n';
	}
	else {
		cout << "0" << '\n';
	}

	return 0;
}