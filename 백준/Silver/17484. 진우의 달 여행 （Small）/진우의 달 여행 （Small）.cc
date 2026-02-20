#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct Node {
	int from_topright, from_top, from_topleft;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int INF = 1e7;

	int N, M;
	cin >> N >> M;

	vector<vector<int>> space(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> space[i][j];
		}
	}
	vector<vector<Node>> dp(N, vector<Node>(M, { INF, INF, INF }));
	//영번째 열까지는 초기값으로 직접 계산
	for (int i = 0; i < M; i++) {
		dp[0][i].from_top = space[0][i];
		dp[0][i].from_topleft = space[0][i];
		dp[0][i].from_topright = space[0][i];
	}

	//첫번째 열부터는 DP로 계산
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j].from_top = min(dp[i - 1][j].from_topleft, dp[i - 1][j].from_topright) + space[i][j];
			if (j > 0) {
				dp[i][j].from_topleft = min(dp[i - 1][j - 1].from_top, dp[i - 1][j - 1].from_topright) + space[i][j];
			}
			if (j < M - 1) {
				dp[i][j].from_topright = min(dp[i - 1][j + 1].from_top, dp[i - 1][j + 1].from_topleft) + space[i][j];
			}
		}
	}
	int min_val;
	min_val = min({ dp[N - 1][0].from_top, dp[N - 1][0].from_topleft, dp[N - 1][0].from_topright });
	for (int i = 1; i < M; i++) {
		int temp_min = min({ dp[N - 1][i].from_top, dp[N - 1][i].from_topleft, dp[N - 1][i].from_topright });
		if (temp_min < min_val) {
			min_val = temp_min;
		}
	}
	cout << min_val << '\n';

	return 0;
}