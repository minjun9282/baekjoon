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

		// K x N 동적배열 할당
		int** num_of_peo = new int* [K+1];
		for (int i = 0; i < K+1; i++) {
			num_of_peo[i] = new int[N];
		}
		
		// 0층 i호에 사는 거주 인원 수 설정
		for (int i = 0; i < N; i++) {
			num_of_peo[0][i] = i + 1;
		}

		// 1층 ~ k층 까지 각 호실의 거주 인원 수를 일단 0으로 초기화함. (다음 단계에서의 계산을 위해)
		for (int i = 1; i < K+1; i++) {
			fill_n(num_of_peo[i], N, 0);
		}

		// K층 n호에 사는 사람의 수 계산
		for (int i = 1; i < K+1; i++) {
			for (int j = 0; j < N; j++) {
				for (int h = 0; h < j + 1; h++) {
					num_of_peo[i][j] += num_of_peo[i - 1][h];
				}
			}
		}

		// 결과값 출력 밑 2차원 동적배열 할당 해제
		cout << num_of_peo[K][N - 1] << '\n';

		for (int i = 0; i < K; i++) {
			delete[] num_of_peo[i];
		}
		delete[] num_of_peo;
		i++;
	}

	return 0;
}