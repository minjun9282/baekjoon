#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	//1.A,B 배열 입력받기
	cin >> N;
	int** A = new int*[N];
	int** B = new int*[N];
	for (int i = 0; i < N; i++) {
		A[i] = new int[2];
		B[i] = new int[2];
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i][0];
		A[i][1] = 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i][0];
		B[i][1] = 0;
	}
	
	//2. A, B 배열 정렬
	int min_index = 0;
	int min = 101;
	int i = 0;
	while (i < N) {
		for (int j = 0; j < N; j++) {
			if (A[j][0] <= min && A[j][1] == 0) {
				min = A[j][0];
				min_index = j;
			}
		}
		min = 101;
		A[min_index][1] = i + 1;
		i++;
	}
	
	min_index = 0;
	min = 101;
	i = 0;
	while (i < N) {
		for (int j = 0; j < N; j++) {
			if (B[j][0] <= min && B[j][1] == 0) {
				min = B[j][0];
				min_index = j;
			}
		}
		min = 101;
		B[min_index][1] = i + 1;
		i++;
	}

	//3. 동적배열 할당 해제 및 최소값 출력
	int temp_a, temp_b, min_result = 0;
	i = 0;
	while (i < N) {
		int j = 0;
		while (true) {
			if (A[j][1] == i + 1) {
				temp_a = A[j][0];
				break;
			}
			else {
				j++;
			}
		}
		int k = 0;
		while (true) {
			if (B[k][1] == N - i) {
				temp_b = B[k][0];
				break;
			}
			else {
				k++;
			}
		}
		min_result += temp_a * temp_b;
		i++;
	}
	cout << min_result << '\n';

	for (int i = 0; i < N; i++) {
		delete[] A[i];
		delete[] B[i];
	}

	delete[] A;
	delete[] B;

	return 0;
}