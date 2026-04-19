#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

struct Chess {
    int row_num_;
    int col_num_;
    int dir_; //1: 오른쪽, 2:왼쪽, 3:위쪽, 4:아랫쪽
};

bool move_piece(int idx, vector<Chess>& chessmen, vector<vector<int>>& color, vector<vector<vector<int>>>& board, int N) {
    int y = chessmen[idx].row_num_;
    int x = chessmen[idx].col_num_;
    int dir = chessmen[idx].dir_;

    int pos = -1;
    for (int i = 0; i < board[y][x].size(); i++) {
        if (board[y][x][i] == idx) {
            pos = i;
            break;
        }
    }

    vector<int> moving;
    for (int i = pos; i < board[y][x].size(); i++) {
        moving.push_back(board[y][x][i]);
    }
    board[y][x].erase(board[y][x].begin() + pos, board[y][x].end());

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    // 범위 밖이거나 파란색이면 방향 반대로
    if (ny < 0 || ny >= N || nx < 0 || nx >= N || color[ny][nx] == 2) {
        if (dir == 1) { 
            dir = 2; 
        }
        else if (dir == 2) {
            dir = 1;
        }
        else if (dir == 3) {
            dir = 4;
        }
        else { 
            dir = 3; 
        }

        chessmen[idx].dir_ = dir;

        ny = y + dy[dir];
        nx = x + dx[dir];

        // 반대 방향도 범위 밖이거나 파란색이면 이동 안 함
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || color[ny][nx] == 2) {
            for (int piece : moving) {
                board[y][x].push_back(piece);
            }
            return false;
        }
    }

    // 빨간색이면 순서 뒤집기
    if (color[ny][nx] == 1) {
        reverse(moving.begin(), moving.end());
    }

    for (int piece : moving) {
        chessmen[piece].row_num_ = ny;
        chessmen[piece].col_num_ = nx;
        board[ny][nx].push_back(piece);
    }

    if (board[ny][nx].size() >= 4) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> color(N, vector<int>(N));
    vector<vector<vector<int>>> board(N, vector<vector<int>>(N));
    vector<Chess> chessmen(K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> color[i][j]; //0: 흰색, 1: 빨간색, 2: 파란색
        }
    }

    for (int i = 0; i < K; i++) {
        int row, col, dir;
        cin >> row >> col >> dir;
        row--;
        col--;

        chessmen[i] = { row, col, dir };
        board[row][col].push_back(i);
    }

    for (int turn = 1; turn <= 1000; turn++) {
        for (int i = 0; i < K; i++) {
            if (move_piece(i, chessmen, color, board, N)) {
                cout << turn << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}