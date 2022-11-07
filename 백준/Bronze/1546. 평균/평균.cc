#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, max;
	double average, total = 0;

	cin >> N;
	int* score = new int[N];
	cin >> score[0];
	max = score[0];
	for (int i = 1; i < N; i++) {
		cin >> score[i];
		if (score[i] > max) {
			max = score[i];
		}
	}
	cout << fixed;
	cout.precision(6);
	for (int j = 0; j < N; j++) {
		total += score[j] / double(max) * 100;
	}
	average = total / N;
	cout << average << '\n';

	delete[] score;

	return 0;
}