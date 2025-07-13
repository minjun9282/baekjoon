#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int dx[4] = {0, 0, -1, 1}; // 동 1, 서 2, 북 3, 남 4
int dy[4] = {1, -1, 0, 0};
vector<int> dice = {1, 2, 3, 4, 5, 6}; //각 위치는 전개도 순서 따름
vector<vector<int>> map;
int result = 0;

void move(vector<int> &dice, int &current_x, int &current_y, int &command, vector<vector<int>> &map) {
    int next_x = current_x + dx[command - 1];
    int next_y = current_y + dy[command - 1];
    
    // 이동 불가시 반대 방향으로 한 칸 이동
    if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
        if (command == 1){ 
            command = 2;
        }
        else if (command == 2){
           command = 1;
        } 
        else if (command == 3){
            command = 4;
        } 
        else if (command == 4){
            command = 3;
        } 
        next_x = current_x + dx[command - 1];
        next_y = current_y + dy[command - 1];
    }

    current_x = next_x;
    current_y = next_y;

    // 주사위 회전
    int top = dice[0], north = dice[1], east = dice[2], west = dice[3], south = dice[4], bottom = dice[5];
    if (command == 1) { // 동
        dice[0] = west; dice[1] = north; dice[2] = top; dice[3] = bottom; dice[4] = south; dice[5] = east;
    }
    else if (command == 2) { // 서
        dice[0] = east; dice[1] = north; dice[2] = bottom; dice[3] = top; dice[4] = south; dice[5] = west;
    }
    else if (command == 3) { // 북
        dice[0] = south; dice[1] = top; dice[2] = east; dice[3] = west; dice[4] = bottom; dice[5] = north;
    }
    else { // 남
        dice[0] = north; dice[1] = bottom; dice[2] = east; dice[3] = west; dice[4] = top; dice[5] = south;
    }

    // BFS 점수 계산
    int B = map[current_x][current_y];
    int C = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    q.push({current_x, current_y});
    visited[current_x][current_y] = true;
    C++;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] == B) {
                visited[nx][ny] = true;
                C++;
                q.push({nx, ny});
            }
        }
    }

    result += B * C;


    bottom = dice[5];
    if (bottom > B){
        if (command == 1){ 
            command = 4;
        }
        else if (command == 2){
            command = 3;
        }
        else if (command == 3){ 
            command = 1;
        }
        else if (command == 4){ 
            command = 2;
        }
    }
    else if (bottom < B){
        if (command == 1){ 
            command = 3;
        }
        else if (command == 2) {
            command = 4;
        }
        else if (command == 3) {
            command = 2;
        }
        else if (command == 4) {
            command = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    map.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int current_x = 0, current_y = 0;
    int command = 1;

    for (int i = 0; i < K; i++) {
        move(dice, current_x, current_y, command, map);
    }

    cout << result << '\n';
    
    return 0;
}
