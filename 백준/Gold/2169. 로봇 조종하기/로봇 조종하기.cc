#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<int>> dp;
vector<vector<int>> dp_right;
vector<vector<int>> dp_left;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    map.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, 0));
    dp_right.resize(N, vector<int>(M, 0));
    dp_left.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    //왼쪽, 오른쪽, 아래쪽으로 이동 가능. 한번 탐사한 지역은 탐사하지 않음.
    dp[0][0] = map[0][0];
    
    //첫번째 행은 오른쪽 이동만 가능하므로 미리 채워줌.
    for (int i = 1; i < M; i++){
        dp[0][i] = dp[0][i-1] + map[0][i];
    }
    
    //두번째 행부터 dp배열은 오른쪽 방향이동과 왼쪽 방향 이동을 비교하여 계산
    for (int i = 1; i < N; i++){
        //일단 오른쪽 이동 방향만 고려
        dp_right[i][0] = dp[i-1][0] + map[i][0]; //바로 위에서 내려오는 경우로 초기화
        for (int j = 1; j < M; j++){
            dp_right[i][j] = max(dp[i-1][j] + map[i][j], dp_right[i][j-1] + map[i][j]);
        }
        // 왼쪽 이동 방향만 고려
        dp_left[i][M-1] = dp[i-1][M-1] + map[i][M-1]; //바로 위에서 내려오는 경우로 초기화
        for (int j = M-2; j >= 0; j--){
            dp_left[i][j] = max(dp[i-1][j] + map[i][j], dp_left[i][j+1] + map[i][j]);
        }
        // 각 칸의 dp는 dp_right값과 dp_left값을 비교
        for (int j = 0; j < M; j++){
            dp[i][j] = max(dp_right[i][j], dp_left[i][j]);
        }
    }
    
    cout << dp[N-1][M-1] << '\n';
    
    return 0;
}