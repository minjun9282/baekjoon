#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> visited;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<int> results;
vector<vector<int>> map;

void bfs(int x, int y, int n, int m){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int size = 1;
    
    while(!q.empty()){
        auto [cur_x, cur_y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && map[nx][ny] == 1){
                q.push({nx, ny});
                visited[nx][ny] = true;
                size += 1;
            }
        }
    }
    results.push_back(size);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] & map[i][j] == 1){
                bfs(i, j, n, m);
            }
        }
    }
    cout << results.size() << '\n';
    if (!results.empty()){
        int max_size = *max_element(results.begin(), results.end());
        cout << max_size << '\n';  
    } 
    else{
        cout << 0 << '\n';
    }
    
    return 0;
}