#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> maps;
bool visited[16][16];
int N;
int answer = 0;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

void dfs(int x, int y, int dir){
    if (x == N-1 && y == N-1){
        answer += 1;
        return;
    }
    
    visited[x][y] = true;

    for (int i = 0; i < 3; i++){
        if ((dir == 0 && i == 1) || (dir == 1 && i == 0)) {
            continue;
        }

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N){
            if (i < 2){ // 가로나 세로 이동
                if (!maps[nx][ny] && !visited[nx][ny]){
                    dfs(nx, ny, i);
                }
            }
            else{ // 대각선 이동
                if (!maps[nx][ny] && !maps[x][ny] && !maps[nx][y] && !visited[nx][ny]){
                    dfs(nx, ny, i);
                }
            }
        }
    }

    visited[x][y] = false; // 백트래킹 원상 복구
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    maps.resize(N, vector<int>(N));
    
    //1. 집의 상태 입력 받기
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> maps[i][j];
        }
    }
    dfs(0, 1, 0);
    
    cout << answer << '\n';
    
    return 0;
}