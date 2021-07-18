#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	int min_package = 1001;
	int min_piece = 1001;
	cin >> N >> M;
	int temp_package, temp_piece, result;
	int i = 0;
	while (i < M) {
		cin >> temp_package >> temp_piece;
		if (temp_package < min_package) {
			min_package = temp_package;
		}
		if (temp_piece < min_piece) {
			min_piece = temp_piece;
		}
		i++;
	}
	if (min_package > min_piece * 6) {
		result = min_piece * N;
	}
	else if ((N / 6 + 1) * min_package < (N / 6 * min_package + N % 6 * min_piece)){
		result = (N / 6 + 1) * min_package;
	}
	else {
		result = (N / 6) * min_package + (N % 6) * min_piece;
	}
	cout << result << '\n';

	return 0;
}