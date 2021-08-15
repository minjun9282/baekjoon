#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int a, b;
	int rem[10][4];
	int* result = new int[T];
	rem[0][0] = 10; rem[0][1] = 10; rem[0][2] = 10; rem[0][3] = 10;
	rem[1][0] = 1; rem[1][1] = 1; rem[1][2] = 1; rem[1][3] = 1;
	rem[2][0] = 2; rem[2][1] = 4; rem[2][2] = 8; rem[2][3] = 6;
	rem[3][0] = 3; rem[3][1] = 9; rem[3][2] = 7; rem[3][3] = 1;
	rem[4][0] = 4; rem[4][1] = 6; rem[4][2] = 4; rem[4][3] = 6;
	rem[5][0] = 5; rem[5][1] = 5; rem[5][2] = 5; rem[5][3] = 5;
	rem[6][0] = 6; rem[6][1] = 6; rem[6][2] = 6; rem[6][3] = 6;
	rem[7][0] = 7; rem[7][1] = 9; rem[7][2] = 3; rem[7][3] = 1;
	rem[8][0] = 8; rem[8][1] = 4; rem[8][2] = 2; rem[8][3] = 6;
	rem[9][0] = 9; rem[9][1] = 1; rem[9][2] = 9; rem[9][3] = 1;
	int i = 0;
	while (i < T) {
		cin >> a >> b;
		a = a % 10;
		b = b % 4 - 1;
		if (b == -1) {
			b += 4;
		}
		result[i] = rem[a][b];
		i++;
	}
	for (int j = 0; j < T; j++) {
		cout << result[j] << '\n';
	}
	delete[] result;

	return 0;
}