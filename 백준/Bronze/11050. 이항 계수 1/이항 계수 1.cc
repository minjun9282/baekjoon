#include <iostream>
using namespace std;

//이항계수 구하기

int fac(int N);
int com(int N, int K);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	cout << com(N, K) << '\n';

	return 0;
}

int fac(int N) {
	if (N == 0) {
		return 1;
	}
	else {
		return N * fac(N - 1);
	}
}

int com(int N, int K) {
	int result;
	result = fac(N) / (fac(K) * fac(N - K));
	return result;
}