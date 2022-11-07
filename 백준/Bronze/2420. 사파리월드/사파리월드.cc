#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int N, M;
	cin >> N >> M;
	cout << abs((N - M)) << '\n';

	return 0;
}