#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Price {
	int red;
	int green;
	int blue;
};

struct cumulative_Cost {
	int use_red;
	int use_green;
	int use_blue;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<Price> houses(N);
	for (int i = 0; i < N; i++) {
		cin >> houses[i].red >> houses[i].green >> houses[i].blue;
	}

	vector<cumulative_Cost> dp(N);
	dp[0].use_red = houses[0].red; dp[0].use_green = houses[0].green; dp[0].use_blue = houses[0].blue;
	for (int i = 1; i < N; i++) {
		dp[i].use_red = min(dp[i - 1].use_blue + houses[i].red, dp[i - 1].use_green + houses[i].red);
		dp[i].use_blue = min(dp[i - 1].use_red + houses[i].blue, dp[i - 1].use_green + houses[i].blue);
		dp[i].use_green = min(dp[i - 1].use_red + houses[i].green, dp[i - 1].use_blue + houses[i].green);
	}
	int min_result = min({ dp[N - 1].use_blue, dp[N - 1].use_green, dp[N - 1].use_red });

	cout << min_result << '\n';

	return 0;
}