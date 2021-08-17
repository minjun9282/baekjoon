#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//1.N, M과 직사각형에 들어갈 숫자 입력받기
	int N, M;
	cin >> N >> M;
	string num;
	int** rect = new int* [N];
	for (int i = 0; i < N; i++) {
		rect[i] = new int[M];
		cin >> num;
		for (int j = 0; j < M; j++) {
			rect[i][j] = stoi(num.substr(j,1));
		}
	}

	//2. 가장 큰 정사각형 찾기
	int start = (N <= M) ? N : M;
	bool found = false;
	while (!found) {
		for (int i = 0; i + start - 1 < N ; i++) {
			for (int j = 0; j + start - 1 < M; j++) {
				if ((rect[i][j] == rect[i][j + start - 1]) && (rect[i + start - 1][j]== rect[i + start - 1][j + start - 1])) {
					if (rect[i][j] == rect[i + start - 1][j]) {
						found = true;
					}
				}
			}
		}
		if ((start == 1) || (found == true)) {
			break;
		}
		else{
			start--;
		}
	}
	cout << start * start << '\n';

	//3. 동적배열 할당 해제
	for (int i = 0; i < N; i++) {
		delete[] rect[i];
	}
	delete[] rect;

	return 0;
}