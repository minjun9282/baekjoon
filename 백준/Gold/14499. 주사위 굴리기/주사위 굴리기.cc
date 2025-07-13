#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int dx[4] = {0, 0, -1, 1}; // 동, 서, 북, 남
int dy[4] = {1, -1, 0, 0};

void move(vector<int> &dice, int &current_x, int &current_y, int command, vector<vector<int>> &map) {
    int next_x = current_x + dx[command - 1];
    int next_y = current_y + dy[command - 1];
    
    if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
        current_x = next_x;
        current_y = next_y;

        int top = dice[0], north = dice[1], east = dice[2], west = dice[3], south = dice[4], bottom = dice[5];//현재 주사위면의 값들
        
        //주사위 굴리는거에 따라 주사위 각 면의 값 변경해줌
        if (command == 1) { // 동쪽
            dice[0] = west; dice[2] = top; dice[5] = east; dice[3] = bottom;
        } 
        else if (command == 2) { // 서쪽
            dice[0] = east; dice[3] = top; dice[5] = west; dice[2] = bottom;
        } 
        else if (command == 3) { // 북쪽
            dice[0] = south; dice[1] = top; dice[5] = north; dice[4] = bottom;
        } 
        else if (command == 4) { // 남쪽
            dice[0] = north; dice[4] = top; dice[5] = south; dice[1] = bottom;
        }

        // 바닥 작업 수행
        if (map[next_x][next_y] == 0) {
            map[next_x][next_y] = dice[5];
        } 
        else {
            dice[5] = map[next_x][next_y];
            map[next_x][next_y] = 0;
        }

        cout << dice[0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> x >> y >> K;
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    vector<int> dice(6, 0); //각 위치는 전개도 순서 따름
    int current_x = x, current_y = y;

    for (int i = 0; i < K; i++) {
        int command;
        cin >> command;
        move(dice, current_x, current_y, command, map);
    }

    return 0;
}
