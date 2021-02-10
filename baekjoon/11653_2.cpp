#include <iostream>
#include <ctime>
using namespace std;

//vector 써서 시간초과 된 것 같아서 array만 썼지만 여전히 큰 소수에서는 시간초과

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	clock_t startTime = clock();
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	bool finished = false;
	int i = 0;

	while ((i < N) && (!finished)) {
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
				while (N % arr[i] == 0) {
					cout << arr[i] << '\n';
					N = N / arr[i];
					if (N == 1) {
						finished = true;
					}
				}
			}
		}
		i++;
	}
	clock_t endTime = clock();
	clock_t elapsed = endTime - startTime;
	double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);
	cout << timeInSecond << '\n';
	return 0;
}