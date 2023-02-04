#include <iostream>
#include <set>
using namespace std;

int n = 5;
int arr[5][5];
int go_x[] = { 0, 0, 1, -1 };
int go_y[] = { 1, -1, 0, 0 };
set<int> result;
void go(int x, int y, int num, int len);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			go(i, j, arr[i][j], 1);
		}
	}
	cout << result.size() << '\n';

	return 0;
}

void go(int x, int y, int num, int len) {
	if (len == 6) {
		result.insert(num);
        return;
	}
	for (int i = 0; i < 4; i++) {
		int pos_x = x + go_x[i];
		int pos_y = y + go_y[i];
		if (pos_x > -1 && pos_x < n && pos_y > -1 && pos_y < n) {
			go(pos_x, pos_y, num * 10 + arr[pos_x][pos_y], len + 1);
		}
	}
}