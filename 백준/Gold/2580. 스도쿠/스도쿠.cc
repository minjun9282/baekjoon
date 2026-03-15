#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
struct Node {
	int row_numbers;
	int col_numbers;
};

bool check(int row_numbers, int col_numbers, int value) {
	bool result = false;
	for (int i = 0; i < 9; i++) {
		if (sudoku[row_numbers][i] != 0 && sudoku[row_numbers][i] == value) {
			return result;
		}
		if (sudoku[i][col_numbers] != 0 && sudoku[i][col_numbers] == value){
			return result;
		}
	}

	for (int k = (row_numbers / 3) * 3; k < (row_numbers / 3) * 3 + 3; k++) {
		for (int j = (col_numbers / 3) * 3; j < (col_numbers / 3) * 3 + 3; j++) {
			if (sudoku[k][j] != 0 && sudoku[k][j] == value) {
				return result;
			}
		}
	}

	return true;
}

void dfs(vector<vector<int>>& sudoku, vector<Node> empty, int idx) {
	if (idx == empty.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	int row_number = empty[idx].row_numbers;
	int col_number = empty[idx].col_numbers;
	for (int k = 1; k < 10; k++) {
		if (check(row_number, col_number, k)) {
			sudoku[row_number][col_number] = k;
			dfs(sudoku, empty, idx + 1);
			sudoku[row_number][col_number] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<Node> empty;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				empty.push_back({ i, j });
			}
		}
	}
	dfs(sudoku, empty, 0);

	return 0;
}