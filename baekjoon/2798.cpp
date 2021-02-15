#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	int* card = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	clock_t startTime = clock();
	int result = 0;
	int gap = M;
	int temp;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				temp = card[i] + card[j] + card[k];
				if ((M - temp <= gap)&&(temp <= M)) {
					gap = abs(M - temp);
					result = temp;
				}
			}
		}
	}
	cout << result << '\n';

	clock_t endTime = clock();

	double timeInSecond = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	cout << timeInSecond << '\n';
	delete[] card;

	return 0;
}