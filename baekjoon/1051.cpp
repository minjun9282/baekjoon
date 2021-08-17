#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//1.N, M�� ���簢���� �� ���� �Է¹ޱ�
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

	//2. ���� ū ���簢�� ã��
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

	//3. �����迭 �Ҵ� ����
	for (int i = 0; i < N; i++) {
		delete[] rect[i];
	}
	delete[] rect;

	return 0;
}