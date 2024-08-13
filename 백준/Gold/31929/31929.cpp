#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }
    
    cin >> M;
    vector<int> L(M);
    for (int i = 0; i < M; ++i) {
        cin >> L[i];
    }
    
    cin >> K;
    
    // DP 테이블 초기화
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1));
    dp[0][0] = 0;
    
    // DP 계산
    for (int i = 0; i < N; i++){
        dp[i+1][0] = dp[i][0] + W[i];
    }
    for (int j = 0; j < M; ++j){
        dp[0][j+1] = dp[0][j] - L[j];
    }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (dp[i][j-1] % K == 0 || dp[i][j-1] < 0){
                dp[i][j] = max(dp[i-1][j] + W[i-1], dp[i][j-1] - L[j-1]);
            }
            else{
                dp[i][j] = max(dp[i-1][j] + W[i-1], dp[i][j-1] - min(L[j-1], dp[i][j-1] % K));
            }
        }
    }
    cout << dp[N][M] << '\n';
    
    return 0;
}
