#include <iostream>
#include <vector>
using namespace std;

//17:50 시작
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//1. 입력받기
	int R, C, T;
	cin >> R >> C >> T;
	vector<vector<int>> house(R + 1, vector<int>(C + 1));
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			cin >> house[i][j];
		}
	}
	//2.
	//2.1) 미세먼지 확산
		//미세먼지는 네 방향으로 확산, 인접한 방향에 공기청정기가 있거나 칸이 없으면(칸이 실제로 없는 경우) 확산되지 않음
		// 확산되는 양은 1/5만큼이고 소수점은 버림, 남은 미세 먼지양은 기존양 - 확산된 양 
	//2.2) 공기청정기 작동(공기 청정기는 1열에 위치, 두 행을 차지)
		// 공기청정기의 위쪽에서는 반시계 방향, 공기청정기의 아랫쪽에서는 시계방향으로 바람이 순환
		// 바람이 불면 미세먼지가 바람의 방향대로 한칸씩 이동
		// 공기청정기로 들어온 미세먼지는 모두 정화됨.
	while (T--) {
		//2.1 미세먼지 확산
		vector<vector<int>> temp = house;
		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				if (house[i][j] != 0 && house[i][j] != -1) {
					int quo, possible_direction = 0;
					quo = house[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny > 0 && ny < R + 1 && nx > 0 && nx < C + 1 && house[ny][nx] != -1) {
							possible_direction++;
							temp[ny][nx] += quo;
						}
					}
					temp[i][j] -= quo * possible_direction;
				}
			}
		}
		//2.2 공기청정기 작동
		bool upper = false;
		for (int i = 1; i < R + 1; i++) {
			if (temp[i][1] == -1 && upper == false) {
				upper = true;
				for (int j = i - 1; j > 1; j--) {
					temp[j][1] = temp[j - 1][1];
				}
				for (int j = 1; j < C; j++) {
					temp[1][j] = temp[1][j + 1];
				}
				for (int j = 1; j < i; j++) {
					temp[j][C] = temp[j + 1][C];
				}
				for (int j = C; j > 2; j--) {
					temp[i][j] = temp[i][j - 1];
				}
				temp[i][2] = 0;
			}
			else if (temp[i][1] == -1 && upper == true) {
				for (int j = i + 1; j < R; j++) {
					temp[j][1] = temp[j + 1][1];
				}
				for (int j = 1; j < C; j++) {
					temp[R][j] = temp[R][j + 1];
				}
				for (int j = R; j > i; j--) {
					temp[j][C] = temp[j - 1][C];
				}
				for (int j = C; j > 2; j--) {
					temp[i][j] = temp[i][j - 1];
				}
				temp[i][2] = 0;
			}
		}
		house = temp;
	}
	int result = 0;
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			if (house[i][j] != -1) {
				result += house[i][j];
			}
		}
	}
	cout << result << '\n';

	return 0;
}