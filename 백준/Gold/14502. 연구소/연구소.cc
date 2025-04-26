#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

//상, 하, 좌, 우 이동
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int max_result = -1;

vector<pair<int, int>> blank;

void bfs(vector<vector<int>>& map, int N, int M){
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (map[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (map[nx][ny] == 0){
                    map[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //1. 지도 크기 입력 받기
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    
    //2. 지도에 값 입력 받기
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if (map[i][j] == 0){
                pair<int, int> blank_coord = make_pair(i, j);
                blank.push_back(blank_coord);
            }
        }
    }
    //3. 벽을 적절한데 세워야함 + 안전 영역의 크기는 bfs로 계산(인접한 0을 이용한 경로)
    // N , M <= 8 이므로 지도는 최대 64칸, 64칸 중에 벽 3개 놓는 경우의 수는 64C3 = 41664 -> 숫자 0이 놓인 칸 모든 조합 시도해봐도 됨.
    // (벽 3개 모든 경우의 수) X (2가 있는 위치에서 bfs) : 상한은 64C3 * 64 = 2666496으로 많지는 않음.
    // 즉, 1. 벽 3개 놓는 모든 조합에 대해
    // 2. 각 조합마다 BFS로 바이러스(2) 퍼뜨리고
    // 3. 안전 영역의 크기(0의 갯수)를 계산
    sort(blank.begin(), blank.end());
    int len = blank.size();
    vector<bool> temp(len);
    fill(temp.end()-3, temp.end(), true);
    do {
        // 벽 원본 복사
        vector<vector<int>> temp_map = map;
        int wall_count = 0;
        
        for (int i = 0; i < len; i++){
            if (temp[i]){
                int x = blank[i].first;
                int y = blank[i].second;
                temp_map[x][y] = 1;
                wall_count++;
                if (wall_count == 3){
                    break;
                }
            }
        }
        
        // 바이러스 확산 시키기
        bfs(temp_map, N, M);
        
        // 안전 영역 최대 크기 갯수 계산하기
        int result = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (temp_map[i][j] == 0){
                    result += 1;
                }
            }
        }
        
        if (result > max_result){
            max_result = result;
        }
    }while(next_permutation(temp.begin(), temp.end()));
    
    cout << max_result << '\n';
    
    return 0;
}