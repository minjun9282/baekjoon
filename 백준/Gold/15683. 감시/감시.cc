#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
int answer = 1e9;
vector<vector<vector<pair<int, int>>>> cctv(5, vector<vector<pair<int, int>>>(4));
vector<pair<int, int>> cameras; //office에서 camera가 존재하는 좌표 저장
vector<vector<int>> office(N, vector<int>(M));

void surveillance(vector<vector<int>>& temp_office, int x, int y, pair<int, int> dir) {//dir 방향으로 벽 만나기 전까지 빈칸을 -1로 만듦.
	int nx = x;
	int ny = y;
	while (true) {
		nx += dir.first;
		ny += dir.second;
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			break;
		}
		if (temp_office[nx][ny] == 6) {
			break;
		}
		if (temp_office[nx][ny] == 0) {
			temp_office[nx][ny] = -1; //설명 속 #대신 -1로 둠
		}
	}
}

void dfs(int idx, vector<vector<int>> temp_office) {
	if (idx == cameras.size()) {
		int blind = 0; //현재 temp_office에서 사각지대의 갯수
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp_office[i][j] == 0) {
					blind++;
				}
			}
		}
		answer = min(answer, blind);
		return;
	}
	int x = cameras[idx].first;
	int y = cameras[idx].second;
	int type = office[x][y] - 1;

	for (int r = 0; r < 4; r++) {
		if (cctv[type][r].empty()) {
			continue;
		}
		vector<vector<int>> temp = temp_office;
		for (auto dir : cctv[type][r]) {
			surveillance(temp, x, y, dir);
		}
		dfs(idx + 1, temp);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//1번 cctv - 4종류
	cctv[0][0].push_back(make_pair(0, 1)); cctv[0][1].push_back(make_pair(1, 0)); 
	cctv[0][2].push_back(make_pair(0, -1)); cctv[0][3].push_back(make_pair(-1, 0));

	//2번 cctv - 2종류
	cctv[1][0].push_back(make_pair(0, 1)); cctv[1][0].push_back(make_pair(0, -1)); 
	cctv[1][1].push_back(make_pair(-1, 0)); cctv[1][1].push_back(make_pair(1, 0));

	//3번 cctv - 4종류
	cctv[2][0].push_back(make_pair(-1, 0)); cctv[2][0].push_back(make_pair(0, 1)); 
	cctv[2][1].push_back(make_pair(0, 1)); cctv[2][1].push_back(make_pair(1, 0)); 
	cctv[2][2].push_back(make_pair(1, 0)); cctv[2][2].push_back(make_pair(0, -1));
	cctv[2][3].push_back(make_pair(0, -1)); cctv[2][3].push_back(make_pair(-1, 0));

	//4번 cctv - 4종류
	cctv[3][0].push_back(make_pair(0, 1)); cctv[3][0].push_back(make_pair(0, -1)); cctv[3][0].push_back(make_pair(-1, 0));
	cctv[3][1].push_back(make_pair(-1, 0)); cctv[3][1].push_back(make_pair(0, 1)); cctv[3][1].push_back(make_pair(1, 0));
	cctv[3][2].push_back(make_pair(0, 1)); cctv[3][2].push_back(make_pair(1, 0)); cctv[3][2].push_back(make_pair(0, -1));
	cctv[3][3].push_back(make_pair(1, 0)); cctv[3][3].push_back(make_pair(0, -1)); cctv[3][3].push_back(make_pair(-1, 0));

	//5번 cctv - 1종류
	cctv[4][0].push_back(make_pair(0, 1)); cctv[4][0].push_back(make_pair(0, -1)); cctv[4][0].push_back(make_pair(-1, 0)); cctv[4][0].push_back(make_pair(1, 0));

	cin >> N >> M;
	office.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j]; //0은 빈칸, 1~5는 cctv, 6은 벽
			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cameras.push_back({ i, j });
			}
		}
	}

	//cctv 최대 갯수 8개 -> 4^8하면 65536개 밖에 안됨 -> 브루트 포스
	dfs(0, office);
	cout << answer << '\n';

	return 0;
}