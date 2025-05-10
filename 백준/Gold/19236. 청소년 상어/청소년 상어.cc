#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

vector<pair<int, int>> fish_order(const vector<vector<pair<int, int>>>& maps) {
    vector<pair<int, int>> order(16, {-1, -1}); // 1~16번 물고기 위치 저장
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a = maps[i][j].first;
            if (a > 0) order[a - 1] = {i, j};
        }
    }
    return order;
}

void move_fish(vector<vector<pair<int, int>>> &maps, vector<pair<int, int>> &order, int shark_x, int shark_y) {
    for (int i = 0; i < 16; i++) {
        auto [x, y] = order[i];
        if (x == -1) continue;

        int dir = maps[x][y].second;

        for (int j = 0; j < 8; j++) {
            int ndir = (dir + j) % 8;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if (nx == shark_x && ny == shark_y) continue;

            pair<int, int> temp = maps[nx][ny];
            maps[nx][ny] = {i + 1, ndir};
            maps[x][y] = temp;

            if (temp.first > 0) order[temp.first - 1] = {x, y};
            order[i] = {nx, ny};
            break;
        }
    }
}

void dfs(vector<vector<pair<int, int>>> maps, vector<pair<int, int>> order, int sx, int sy, int dir, int score, int &max_score) {
    move_fish(maps, order, sx, sy);

    bool moved = false;

    for (int step = 1; step <= 3; step++) {
        int nx = sx + dx[dir] * step;
        int ny = sy + dy[dir] * step;

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if (maps[nx][ny].first <= 0) continue;

        auto temp_maps = maps;
        auto temp_order = order;

        int fish_num = temp_maps[nx][ny].first;
        int new_dir = temp_maps[nx][ny].second;
        temp_order[fish_num - 1] = {-1, -1};
        temp_maps[sx][sy].first = 0;
        temp_maps[nx][ny].first = -1;

        dfs(temp_maps, temp_order, nx, ny, new_dir, score + fish_num, max_score);
        moved = true;
    }

    if (!moved) {
        max_score = max(max_score, score);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<pair<int, int>>> maps(4, vector<pair<int, int>>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            maps[i][j] = {a, b - 1};
        }
    }

    int result = 0;
    int first_fish = maps[0][0].first;
    int first_dir = maps[0][0].second;
    result += first_fish;
    maps[0][0].first = -1;

    vector<pair<int, int>> order = fish_order(maps);
    order[first_fish - 1] = {-1, -1};

    dfs(maps, order, 0, 0, first_dir, result, result);

    cout << result << '\n';
    return 0;
}
