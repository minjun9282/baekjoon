#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int N, g_N = 0;
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		g_N += (N / i) * i;
	}
	cout << g_N << '\n';

	return 0;
}