#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int* ary = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}
	int temp, minimum, index;
	for (int i = 0; i < N - 1; i++) {
		minimum = ary[i + 1];
		for (int j = i + 1; j < N; j++) {
			temp = ary[j];
			if (temp <= minimum) {
				minimum = temp;
				index = j;
			}
		}
		if (ary[i] > minimum) {
			temp = ary[i];
			ary[i] = minimum;
			ary[index] = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ary[i] << '\n';
	}

	return 0;
}