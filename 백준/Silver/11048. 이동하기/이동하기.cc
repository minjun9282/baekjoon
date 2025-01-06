#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    //오른쪽, 아래, 오른쪽 아래 대각선과 같이 세 방향으로 이동 가능.
    int maze[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> maze[i][j];
        }
    }
    int dp[N][M];
    dp[0][0] = maze[0][0];
    // 첫번째 행 누적합으로 표현
    for (int j = 1; j < M; j++){
        dp[0][j] = maze[0][j] + dp[0][j-1] ;
    }
    // 첫번째 열 누적합으로 표현
    for (int i = 1; i < N; i++){
        dp[i][0] = maze[i][0] + dp[i-1][0];
    }
    // dp 계산
    for (int i = 1; i < N; i++){
        for (int j = 1; j < M; j++){
            dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + maze[i][j];
        }
    }
    cout << dp[N-1][M-1] << '\n';
    
    return 0;
}