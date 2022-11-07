#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	double average;
	cin >> N;
	int i = 0;
	int** test_case = new int*[N];
	double* over_average = new double[N];
	fill_n(over_average, N, 0);

	cout << fixed;
	cout.precision(3);

	while (i < N) {
		cin >> M;
		double total = 0;
		double num_of_student = 0;
		test_case[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> test_case[i][j];
			total += test_case[i][j];
		}
		average = total / M;
		for (int j = 0; j < M; j++) {
			if (test_case[i][j] > average) {
				num_of_student++;
			}
		}
		over_average[i] = num_of_student / M * 100;
		i++;
	}
	
	for (int i = 0; i < N; i++) {
		cout << over_average[i] << '%' << '\n';
	}
	for (int i = 0; i < N; i++) {
		delete[] test_case[i];
	}
	delete[] test_case;
	delete[] over_average;

	return 0;
}