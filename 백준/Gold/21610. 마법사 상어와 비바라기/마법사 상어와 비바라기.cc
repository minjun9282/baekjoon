#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}; //대각 방향은 1, 3, 5, 7
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 대각 방향은 1, 3, 5, 7
vector<pair<int, int>> clouds;

int check(int x, int y, vector<vector<int>>& map){
    int count = 0;
    int n = map.size();
    if (x-1 >= 0 && y-1 >= 0 && map[x-1][y-1] > 0){
        count++;
    }
    if (x-1 >= 0 && y+1 < n && map[x-1][y+1] > 0){
        count++;
    }
    if (x+1 < n && y+1 < n && map[x+1][y+1] > 0){
        count++;
    }
    if (x+1 < n && y-1 >= 0 && map[x+1][y-1] > 0){
        count++;
    }
    return count;
}

void move(int d_i, int s_i, vector<vector<int>>& map){
    int n = map.size();
    int move_x = dx[d_i-1] * (s_i % n);
    int move_y = dy[d_i-1] * (s_i % n);
    vector<pair<int, int>> new_targets;
    
    // 구름 이동하고 비 내리기
    for (auto& cloud : clouds){
        int x = (cloud.first + move_x + n) % n;
        int y = (cloud.second + move_y + n) % n;
        new_targets.push_back({x, y});
    }
    
    for (auto [x,y] : new_targets){
        map[x][y] += 1;
    }
    // 물복사 마법 시전
    for (auto [x, y] : new_targets){
        map[x][y] += check(x, y, map);
    }
    // 구름 다시 생성
    vector<vector<bool>> was_cloud(n, vector<bool>(n, false)); // new_targets에 있었던 지점은 구름 있었던 지점으로 bool 자료형으로 관리
    for (auto [x, y] : new_targets){
        was_cloud[x][y] = true;
    }
    
    vector<pair<int, int>> new_clouds;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (!was_cloud[i][j] && map[i][j] >= 2){
                new_clouds.push_back({i, j});
                map[i][j] -= 2;
            }
        }
    }
    clouds = new_clouds;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    clouds = {{N-1, 0}, {N-1, 1}, {N-2, 0}, {N-2, 1}};
    
    while(M--){
        int d_i, s_i;
        cin >> d_i >> s_i;
        move(d_i, s_i, map);
    }
    
    int result = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result += map[i][j];
        }
    }
    
    cout << result << '\n';
    
    return 0;
}