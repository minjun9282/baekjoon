#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct item {
	int weight;
	int value;
};

int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, W, V, K;
	cin >> N >> K;
	vector<item> knapsack(N + 1);
	for (int i = 1; i < N + 1; i++) {
		cin >> knapsack[i].weight >> knapsack[i].value;
	}

	//반드시 무게 당 가치가 높은 애를 포함하는게 best가 아님
	//무게를 꽉 맞게 채운다고 가치의 합이 최대가 되는게 아님
	for (int i = 1; i < N + 1; i++) {
		for (int w = 1; w <= K; w++) {
			if (knapsack[i].weight <= w) {
				dp[i][w] = max(knapsack[i].value + dp[i - 1][w - knapsack[i].weight], dp[i - 1][w]);
			}
			else {
				dp[i][w] = dp[i - 1][w];
			}
				
		}
	}
	cout << dp[N][K] << '\n';

	return 0;
}
