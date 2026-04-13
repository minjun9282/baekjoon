#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Position {
	int y_position_;
	int x_position_;
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int max_height = 0;
	vector<vector<int>> ground(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			ground[i][j] = row[j] - '0';
			if (ground[i][j] > max_height) {
				max_height = ground[i][j];
			}
		}
	}

	//각 층마다 단면을 나눠서 본다고 생각
	//i번째 층에서의 단면은 어떤 칸의 숫자가 i 이상일 경우 1로 표시, i 미만일 경우 0으로 표시
	//이때 0이 있는 곳은 물이 담길 수 있는 칸이고 1은 벽으로 생각할 수 있음
	//숫자 0의 영역에 외곽에 있는 칸이 포함되지 않으면 해당 영역의 0의 갯수만큼 그 층에서는 물을 넣을 수 있음.

	int total_sum = 0;
	int start_floor = 1;
	while (max_height--) {
		vector<vector<int>> plane(N, vector<int>(M));
		vector<vector<bool>> region(N, vector<bool>(M, false));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ground[i][j] >= start_floor) {
					plane[i][j] = 1;
				}
				else {
					plane[i][j] = 0;
				}
			}
		}
		//bfs 알고리즘으로 0끼리 이어진 영역 탐색, 단 경계에 있는 0과 이어질 경우 해당 영역은 무효화
		//만약에 유효한 영역 생성이 완료될 경우 해당 영역의 0의 개수를 total_sum에 합산.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (plane[i][j] == 0 && region[i][j] == false) {
					queue<Position> q;
					q.push({ i, j });
					region[i][j] = true;

					bool is_valid_region = true;
					int region_count = 1;

					while (!q.empty()) {
						int curr_x = q.front().x_position_;
						int curr_y = q.front().y_position_;
						q.pop();

						if (curr_x == 0 || curr_x == M - 1 || curr_y == 0 || curr_y == N - 1) {
							is_valid_region = false;
						}

						for (int dir = 0; dir < 4; dir++) {
							int nx = curr_x + dx[dir];
							int ny = curr_y + dy[dir];

							if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
								continue;
							}
							if (region[ny][nx] == true) {
								continue;
							}
							if (plane[ny][nx] == 1) {
								continue;
							}

							region[ny][nx] = true;
							q.push({ ny, nx });
							region_count++;
						}
					}
					if (is_valid_region == true) {
						total_sum += region_count;
					}
				}
			}
		}

		start_floor++;
	}

	cout << total_sum << '\n';

	return 0;
}
