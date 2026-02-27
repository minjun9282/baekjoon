#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> visited;
int N;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] == map[x][y] && visited[nx][ny] != true) {
				dfs(map, visited, nx, ny);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char input;
			cin >> input;
			if (input == 'R') {
				map[i][j] = 0;
			}
			else if (input == 'G') {
				map[i][j] = 1;
			}
			else {
				map[i][j] = 2;
			}
		}
	}
	int normal = 0, color_blind = 0;
	visited.resize(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				dfs(map, visited, i, j);
				normal++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
			}
		}
	}
	visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				dfs(map, visited, i, j);
				color_blind++;
			}
		}
	}
	cout << normal << " " << color_blind << "\n";

	return 0;
}