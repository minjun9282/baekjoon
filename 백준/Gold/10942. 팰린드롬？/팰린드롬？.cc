#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> num;
vector<vector<int>> dp;

int is_palindrome(int S, int E) {
	if (dp[S][E] != -1){
	    return dp[S][E];
	}
	if (S == E){
	    return dp[S][E] = 1;
	}
	if (S + 1 == E){
	    return dp[S][E] = (num[S] == num[E]);
	}
	
	return dp[S][E] = (num[S] == num[E] && is_palindrome(S + 1, E - 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, S, E;
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	dp.resize(N, vector<int>(N, -1));

	for (int i = 0; i < N; i++){
	    for (int j = i; j < N; j++){
	        is_palindrome(i, j);
	    }
	}
	cin >> M;
	while(M--) {
		cin >> S >> E;
		cout << dp[S-1][E-1] << '\n';
	}

	return 0;
}