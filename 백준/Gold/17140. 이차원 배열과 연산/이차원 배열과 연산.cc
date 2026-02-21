#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

void sort_R(vector<vector<int>>& arr) {
	if (arr.empty() || arr[0].empty()) return;
	int max_R_size = 1;
	vector<vector<pair<int, int>>> sort_arr(arr.size());//sort_arr의 각각의 원소는 arr의 각 열마다 (value, value 개수)쌍의 정보를 담고 있음.
	
	for (int i = 0; i < arr.size(); i++) {
		map<int, int> counts;
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] != 0) { //0은 value로 생각 안함.
				counts[arr[i][j]]++;
			}
		}
		for (auto const& pair : counts) {
			sort_arr[i].push_back(pair);
		}

		sort(sort_arr[i].begin(), sort_arr[i].end(), [](const auto& a, const auto& b) {
			if (a.second != b.second) {
				return a.second < b.second;
			}
			return a.first < b.first;
		}
		);

		if (sort_arr[i].size() * 2 > max_R_size) {
			max_R_size = sort_arr[i].size() * 2;
		}
	}
	max_R_size = min(100, max_R_size);
	vector<vector<int>> new_arr(arr.size(), vector<int>(max_R_size, 0));
	for (int i = 0; i < arr.size(); i++) {
		int limit = min(50, (int)sort_arr[i].size());
		for (int j = 0; j < limit; j++) {
			new_arr[i][j * 2] = sort_arr[i][j].first;
			new_arr[i][j * 2 + 1] = sort_arr[i][j].second;
		}
	}

	arr = new_arr;
	
};

void sort_C(vector<vector<int>>& arr) {
	if (arr.empty() || arr[0].empty()) return;
	int max_C_size = 1; // 0으로 초기화
	vector<vector<pair<int, int>>> sort_arr(arr[0].size()); // 열의 개수만큼 생성

	for (int j = 0; j < arr[0].size(); j++) {
		map<int, int> counts;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i][j] != 0) { // 열(j)은 고정하고 행(i)을 변화시키며 읽음
				counts[arr[i][j]]++;
			}
		}
		for (auto const& pair : counts) {
			sort_arr[j].push_back(pair);
		}

		sort(sort_arr[j].begin(), sort_arr[j].end(), [](const auto& a, const auto& b) {
			if (a.second != b.second) {
				return a.second < b.second;
			}
			return a.first < b.first;
			});

		if (sort_arr[j].size() * 2 > max_C_size) {
			max_C_size = sort_arr[j].size() * 2;
		}
	}

	max_C_size = min(100, max_C_size);
	vector<vector<int>> new_arr(max_C_size, vector<int>(arr[0].size(), 0));
	for (int j = 0; j < arr[0].size(); j++) {
		int limit = min(50, (int)sort_arr[j].size());
		for (int i = 0; i < limit; i++) {
			if (i * 2 + 1 < max_C_size) {
				new_arr[i * 2][j] = sort_arr[j][i].first;
				new_arr[i * 2 + 1][j] = sort_arr[j][i].second;
			}
		}
	}

	arr = new_arr;
};

vector<vector<int>> arr(3, vector<int>(3));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int r, c, k, result = 0;
	cin >> r >> c >> k;
	//연산 한번 하면 1초
	//배열의 인덱스는 1부터 시작한다는데 편의상 r이랑 c에서 1 빼겠음
	r--; 
	c--;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	
	while (true) {
		if (!arr.empty() && !arr[0].empty() && 0 <= r && r < (int)arr.size() && 0 <= c && c < (int)arr[0].size() && arr[r][c] == k) {
			break;
		}

		if (arr.size() >= arr[0].size()) {
			sort_R(arr);
		}
		else {
			sort_C(arr);
		}
		result++;

		if (result > 100) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << result << '\n';

	return 0;
}