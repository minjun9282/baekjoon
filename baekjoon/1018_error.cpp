#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	char** board = new char* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int minimum = 64;
	int diff_11;
	int diff_5;
	char start_11;
	char start_5;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			start_11 = board[i][j];
			start_5 = board[i + 7][j + 7];
			diff_11 = 0;
			diff_5 = 0;
			int length = 0;
			int width = 0;
			while (length < 8) {
				while (width < 8) {
					if (board[i + length][j + width] != start_11) {
						diff_11++;
					}
					if (board[i + length][j + width] != start_5) {
						diff_5++;
					}
					width += 2;
				}
				width = 0;
				length += 2;
			}
			length = 1;
			width = 1;
			while (length < 8) {
				while (width < 8) {
					if (board[i + length][j + width] != start_11) {
						diff_11++;
					}
					if (board[i + length][j + width] != start_5) {
						diff_5++;
					}
					width += 2;
				}
				width = 1;
				length += 2;
			}
			length = 1;
			width = 0;
			while (length < 8) {
				while (width < 8) {
					if (board[i + length][j + width] == start_11) {
						diff_11++;
					}
					if (board[i + length][j + width] == start_5) {
						diff_5++;
					}
					width += 2;
				}
				width = 0;
				length += 2;
			}
			length = 0;
			width = 1;
			while (length < 8) {
				while (width < 8) {
					if (board[i + length][j + width] == start_11) {
						diff_11++;
					}
					if (board[i + length][j + width] == start_5) {
						diff_5++;
					}
					width += 2;
				}
				width = 1;
				length += 2;
			}
			if (diff_11 <= diff_5) {
				if (diff_11 <= minimum) {
					minimum = diff_11;
				}
			}
			else {
				if (diff_5 <= minimum) {
					minimum = diff_5;
				}
			}
		}
	}
	cout << minimum << '\n';

	// 동적할당 해제
	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;

	return 0;
}