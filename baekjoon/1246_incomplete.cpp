#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//1. N, M, Pi 입력받기
	int N, M;
	cin >> N >> M;
	int* arr = new int[M];
	int* num_cust = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
		num_cust[i] = -1;
	}

	//2. Pi 정렬하기 (Pi가 중복될 경우 처리해줘야함.)
	int min_pri = 1001;
	int min_idx = -1;
	int max_idx;
	int j = 0;
	int l = 0;
	while (l < M) {
		for (int i = 0; i < M; i++) {
			if (arr[i] <= min_pri && num_cust[i] == -1) {
				min_pri = arr[i];
				min_idx = i;
			}
		}
		num_cust[min_idx] = M - j;
		min_pri = 1001;
		j++;
		if (l == M - 1) {
			max_idx = min_idx;
		}
		l++;
	}

	//3. 결과 출력 및 동적배열 할당 해제 (5원 4명보다 4원 5명을 출력해야함.)
	int max_result = 0;
	int min_price = arr[max_idx];
	for (int k = 0; k < M; k++) {
		if ((arr[k] * num_cust[k] >= max_result) && (num_cust[k] <= N)) {
			if (arr[k] * num_cust[k] > max_result) {
				max_result = arr[k] * num_cust[k];
				min_price = arr[k];
			}
			else if(arr[k] * num_cust[k] == max_result) {
				if (arr[k] <= min_price) {
					max_result = arr[k] * num_cust[k];
					min_price = arr[k];
				}
			}
		}
	}

	cout << min_price << " " << max_result << '\n';

	delete[] arr;
	delete[] num_cust;

	return 0;
}