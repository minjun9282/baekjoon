#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int N;
	cin >> N;
	int x, y;
	int** ary = new int*[N];
	int* rank = new int[N];
	fill_n(rank, N, 1);
	for (int i = 0; i < N; i++) {
		ary[i] = new int[2];
		cin >> ary[i][0] >> ary[i][1];
	}
	// ����
	clock_t start = clock();
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((ary[i][0] > ary[j][0]) && (ary[i][1] > ary[j][1])) {
				rank[j]++;
			}
			else if ((ary[i][0] < ary[j][0]) && (ary[i][1] < ary[j][1])) {
				rank[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << rank[i] << ' ';
	}
	cout << '\n';

	for (int i = 0; i < N; i++) {
		delete[] ary[i];
	}
	delete[] ary;
	delete[] rank;

	//��
	clock_t end = clock();

	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	cout << duration << '\n';

	return 0;
}