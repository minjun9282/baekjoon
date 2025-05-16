#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
vector<vector<int>> maps;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> unions;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> group;

    q.push({y, x});
    visited[y][x] = true;
    group.push_back({y, x});

    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visited[ny][nx]) continue;

            int diff = abs(maps[cy][cx] - maps[ny][nx]);
            if (diff >= L && diff <= R) {
                visited[ny][nx] = true;
                q.push({ny, nx});
                group.push_back({ny, nx});
            }
        }
    }

    if (group.size() > 1) {
        unions.push_back(group);
    }
}

int move(vector<vector<int>> &maps, vector<vector<pair<int, int>>> &unions, vector<vector<bool>> &visited, int &result){
    while(true){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bfs(i, j);
                }
            }
        }
        int num_groups = unions.size();
        if (num_groups == 0){
            return result;
        }
        for (int i = 0; i < num_groups; i++){
            int total_pop = 0;
            int num_country = unions[i].size();
            for (int j = 0; j < num_country; j++){
                int x = unions[i][j].first;
                int y = unions[i][j].second;
                total_pop += maps[x][y];
            }
            int avg_pop = total_pop / num_country;
            for (int k = 0; k < num_country; k++){
                int x = unions[i][k].first;
                int y = unions[i][k].second;
                maps[x][y] = avg_pop;
            }
        }
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        unions.clear();
        result++;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //1. N, L, R 주어짐
    cin >> N >> L >> R; //두 나라의 인구 차이가 L명 이상 R명 이하
    maps = vector<vector<int>>(N, vector<int>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    
    //2. 각 나라의 인구수 주어짐
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> maps[i][j];
        }
    }
    
    //3. 인구 이동
    // 아래의 방법에 의해 인구 이동이 없을 때 까지 지속됨.
    // 1.국경선을 공유하는 두 나라의 인구차이가 L명 이상, R명 이하라면 국경선을 하루 동안 엶
    // 2.조건에 해당하는 모든 국경선이 열리면 인구 이동을 시작
    // 3.국경선이 열려있고 인접한 칸만을 이용해 이동할 수 있으면 하루 동안 연합이라고 함
    // 4.연합을 이루고 있는 각 칸의 인구수는 평균으로 나눠 가짐. 소수점은 버림
    // 5.인구 이동 끝나면 연합 해체, 모든 국경선 닫음.
    // Q: 인구 이동이 며칠 동안 발생하는가?
    int result = 0;
    int days = move(maps, unions, visited, result);
    cout << days << '\n';
    
    return 0;
}