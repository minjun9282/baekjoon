#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//큰 소수가 입력될 경우 시간 초과

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	clock_t startTime = clock();
	vector<int> prime;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 2) {
			bool found = true;
			int j = 2;
			while (j < N - 1) {
				if ((arr[i] % j == 0) && (j != arr[i])) {
					found = false;
					break;
				}
				else {
					j++;
				}
			}
			if (found == true) {
				prime.push_back(arr[i]);
			}
		}
	}

	for (auto iter = begin(prime); iter != end(prime); iter++) {
		while ((N % *iter) == 0) {
			cout << *iter << '\n';
			N = N / *iter;
		}
	}
	clock_t endTime = clock();
	clock_t elapsed = endTime - startTime;
	double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);
	cout << timeInSecond << '\n';

	return 0;
}