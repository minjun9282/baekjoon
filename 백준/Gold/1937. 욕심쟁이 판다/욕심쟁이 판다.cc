#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<bool>> visited;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> map;
vector<vector<int>> dp;

int dfs(int x, int y, int n){
    if (dp[x][y] != -1){
        return dp[x][y];
    }
    dp[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 1;
    
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] > map[x][y]){
            dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny, n));
        }
    }
    return dp[x][y];
}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 
 int n;
 cin >> n;
 map.resize(n, vector<int>(n));
 visited.resize(n, vector<bool>(n, false));
 dp.resize(n, vector<int>(n, -1)); //아직 값이 없는 곳은 -1로 초기화.
 for (int i = 0; i < n; i++){
     for (int j = 0; j < n; j++){
         cin >> map[i][j];
     }
 }
 int max_length = 0;
 for (int i = 0; i < n; i++){
     for (int j = 0; j < n; j++){
        max_length = max(max_length, dfs(i, j, n));
     }
 }
 cout << max_length << '\n';
 
 return 0;
}