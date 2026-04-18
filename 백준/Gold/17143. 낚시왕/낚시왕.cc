#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 7:34 시작
int dy[5] = {0, -1, 1, 0, 0 };
int dx[5] = {0, 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int R, C, M;
	cin >> R >> C >> M;
	vector<vector<vector<int>>> map(R + 1, vector<vector<int>>(C + 1));
	
	vector<int> shark_velo;
	vector<int> shark_dir;//1:위, 2:아래, 3:오른쪽, 4: 왼쪽
	vector<int> shark_size;
	int total_size = 0;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark_velo.push_back(s);
		shark_dir.push_back(d);
		shark_size.push_back(z);
		map[r][c].push_back(i); //제일 처음 상어를 관리하기 위해 상어마다 고유 번호를 인덱스로 줌.
	}
	//C번만큼 수행
	//낚시왕이 c번째 열로 이동: c열에서 행 인덱스 r이 가장 작은 상어를 잡음 -> total_size에 추가, 해당 상어의 인덱스를 다 -1로 변경
	//상어들이 이동: 방향과 속력을 따져서 이동, 이동 후 한 칸에 여러마리 상어가 있을 시 크기가 가장 큰 상어만 남김 -> 삭제되는 상어의 인덱스를 다 -1로 변경
	for (int i = 1; i <= C; i++) {
		//1. 상어 잡기(상어 없을 가능성도 고려)
		int j = 1;
		while (j <= R) {
			if (map[j][i].size() == 0) {
				j++;
			}
			else {
				bool caught = false;
				for (int k = 0; k < map[j][i].size(); k++) {
					int delete_shark_idx = map[j][i][k];
					if (shark_size[delete_shark_idx] != -1 && caught == false) {//만약에 실제 상어 존재시
						shark_velo[delete_shark_idx] = -1;
						shark_dir[delete_shark_idx] = -1;
						total_size += shark_size[delete_shark_idx];//잡은 상어 크기에 추가.
						shark_size[delete_shark_idx] = -1;
						caught = true;
						break;
					}
				}
				if (caught == false) {
					j++;
				}
				else {
					break;
				}
			}
		}
		//2. 상어 이동
		vector<vector<vector<int>>> temp(R + 1, vector<vector<int>>(C + 1));
		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				if (map[i][j].size() != 0) {//실제 상어가 있는 경우
					//속도, 방향에 따라 이동 후 위치, 방향이 바뀌게 됨
					for (int k = 0; k < map[i][j].size(); k++) {
						int next_dir, next_R, next_C, curr_idx;
						if (shark_size[map[i][j][k]] != -1) {
							curr_idx = map[i][j][k];
							int curr_dir = shark_dir[curr_idx];
							int curr_velo = shark_velo[curr_idx];
							int curr_R = i;
							int curr_C = j;
							if (curr_dir == 1 || curr_dir == 2) {//방향이 위(1) 아래(2)인경우
								curr_velo %= (2 * (R - 1));
								while (curr_velo--) {
									if (curr_dir == 1) {
										if (curr_R == 1) {
											curr_dir = 2;
											curr_R = 2;
										}
										else {
											curr_R = curr_R - 1;
										}
									}
									else {//curr_dir == 2인 경우
										if (curr_R == R) {
											curr_dir = 1;
											curr_R = R - 1;
										}
										else {
											curr_R = curr_R + 1;
										}
									}
								}
							}
							else {//방향이 좌우인 경우
								curr_velo %= (2 * (C - 1));
								while (curr_velo--) {
									if (curr_dir == 3) { //오른쪽
										if (curr_C == C) {
											curr_dir = 4;
											curr_C = C - 1;
										}
										else {
											curr_C = curr_C + 1;
										}
									}
									else {//curr_dir == 4인 경우
										if (curr_C == 1) {
											curr_dir = 3;
											curr_C = 2;
										}
										else {
											curr_C = curr_C - 1;
										}
									}
								}
							}
							//상어 이동 반영 및 방향 반영
							next_R = curr_R;
							next_C = curr_C;
							next_dir = curr_dir;
							shark_dir[curr_idx] = next_dir;
							temp[next_R][next_C].push_back(curr_idx);
						}
					}
					
				}

			}
		}
		// 한칸에 여러 상어 존재하는 경우 처리
		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				vector<int> temp_sharks_size;
				if (temp[i][j].size() > 1) {
					for (int k = 0; k < temp[i][j].size(); k++) {
						int shark_idx = temp[i][j][k];
						if (shark_size[shark_idx] != -1) {
							temp_sharks_size.push_back(shark_idx);
						}
					}
					if (temp_sharks_size.size() > 1) {
						int best_size = shark_size[temp_sharks_size[0]];
						int best_size_idx = temp_sharks_size[0];
						for (int i = 1; i < temp_sharks_size.size(); i++) {
							if (shark_size[temp_sharks_size[i]] > best_size) {
								best_size = shark_size[temp_sharks_size[i]];
								best_size_idx = temp_sharks_size[i];
							}
						}
						for (int i = 0; i < temp_sharks_size.size(); i++) {
							if (temp_sharks_size[i] != best_size_idx) {
								int del_idx = temp_sharks_size[i];
								shark_velo[del_idx] = -1;
								shark_dir[del_idx] = -1;
								shark_size[del_idx] = -1;
							}
						}
					}
				}
			}
		}
		map = temp;
	}
	cout << total_size << '\n';

	return 0;
}