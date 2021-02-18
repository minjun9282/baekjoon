#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, K, N;
	int i = 0;
	cin >> T;
	while (i < T) {
		cin >> K;
		cin >> N;

		// K x N �����迭 �Ҵ�
		int** num_of_peo = new int* [K+1];
		for (int i = 0; i < K+1; i++) {
			num_of_peo[i] = new int[N];
		}
		
		// 0�� iȣ�� ��� ���� �ο� �� ����
		for (int i = 0; i < N; i++) {
			num_of_peo[0][i] = i + 1;
		}

		// 1�� ~ k�� ���� �� ȣ���� ���� �ο� ���� �ϴ� 0���� �ʱ�ȭ��. (���� �ܰ迡���� ����� ����)
		for (int i = 1; i < K+1; i++) {
			fill_n(num_of_peo[i], N, 0);
		}

		// K�� nȣ�� ��� ����� �� ���
		for (int i = 1; i < K+1; i++) {
			for (int j = 0; j < N; j++) {
				for (int h = 0; h < j + 1; h++) {
					num_of_peo[i][j] += num_of_peo[i - 1][h];
				}
			}
		}

		// ����� ��� �� 2���� �����迭 �Ҵ� ����
		cout << num_of_peo[K][N - 1] << '\n';

		for (int i = 0; i < K; i++) {
			delete[] num_of_peo[i];
		}
		delete[] num_of_peo;
		i++;
	}

	return 0;
}