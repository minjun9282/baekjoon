#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

queue<pair<int, int>> tomatoes;
int min_days = 0;
int M, N;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int unripe_num = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> M >> N;
	vector<vector<int>> box(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				tomatoes.push(make_pair(i, j));
			}
			else if (box[i][j] == 0) {
				unripe_num++;
			}
		}
	}
	if (unripe_num == 0) {
		cout << 0 << '\n';
        return 0;
	}
	if (tomatoes.empty()){
		cout << -1 << '\n';
        return 0;
	}
	else {
		while (!tomatoes.empty()) {
			min_days++;
			int curr_num_tomatoes = tomatoes.size();
			for (int i = 0; i < curr_num_tomatoes; i++) {
				pair<int, int> curr = tomatoes.front();
				tomatoes.pop();
				for (int j = 0; j < 4; j++) {
					int nx = curr.first + dy[j];
					int ny = curr.second + dx[j];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && box[nx][ny] == 0) {
						box[nx][ny] = 1;
						unripe_num--;
						tomatoes.push(make_pair(nx, ny));
						if (unripe_num == 0) {
							cout << min_days << '\n';
							return 0;
						}
					}
				}
			}			
			if (tomatoes.empty()) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	return 0;
}