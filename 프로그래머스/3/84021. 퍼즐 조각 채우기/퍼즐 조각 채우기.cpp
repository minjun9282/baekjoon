#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<bool>> visited_table;
vector<vector<bool>> visited_board;
map<pair<int, int>, vector<pair<int, int>>> graph_table;
map<pair<int, int>, vector<pair<int, int>>> graph_board;
vector<vector<vector<pair<int, int>>>> table_blocks; 
vector<vector<pair<int, int>>> board_blocks;
vector<vector<pair<int, int>>> answers;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// 90도 회전 시킴.
vector<pair<int, int>> rotate_90(const vector<pair<int, int>>& block) {
    vector<pair<int, int>> rotated_block;
    for (const auto& cell : block) {
        int x = cell.first;
        int y = cell.second;
        rotated_block.push_back({y, -x});
    }
    return rotated_block;
}

void bfs_board(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> block;
    q.push({x, y});
    block.push_back({x, y});
    visited_board[x][y] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
    
        for (const auto& neighbor : graph_board[{cur_x, cur_y}]) {
            int next_x = neighbor.first;
            int next_y = neighbor.second;
            
            if (!visited_board[next_x][next_y]) {
                visited_board[next_x][next_y] = true;
                q.push({next_x, next_y});
                block.push_back({next_x, next_y});
            }
        }
    }
    
    // blocks의 각 원소들에 대해, 각 원소의 첫번째 값 빼서 모두 (0, 0)으로 만들어줌.
    int base_x = block[0].first;
    int base_y = block[0].second;
    
    for (auto& coord : block) {
        coord.first -= base_x;
        coord.second -= base_y;
    }
    
    sort(block.begin(), block.end());
    board_blocks.push_back(block);
}

void bfs_table(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> block;
    vector<vector<pair<int, int>>> block_list;
    q.push({x, y});
    block.push_back({x, y});
    visited_table[x][y] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
    
        for (const auto& neighbor : graph_table[{cur_x, cur_y}]) {
            int next_x = neighbor.first;
            int next_y = neighbor.second;
            
            if (!visited_table[next_x][next_y]) {
                visited_table[next_x][next_y] = true;
                q.push({next_x, next_y});
                block.push_back({next_x, next_y});
            }
        }
    }
    
    // blocks의 각 원소들에 대해, 각 원소의 첫번째 값 빼서 모두 (0, 0)으로 만들어줌.
    int base_x = block[0].first;
    int base_y = block[0].second;
    
    for (auto& coord : block) {
        coord.first -= base_x;
        coord.second -= base_y;
    }
    
    sort(block.begin(), block.end());
    block_list.push_back(block);
    
    for (int i = 0; i < 3; i++) {  // 총 3번 회전시킨 후 회전시킨 것들도 모두 다 table_blocks에 일단 추가함.
        block = rotate_90(block);
        sort(block.begin(), block.end());
        block_list.push_back(block);
    }
    table_blocks.push_back(block_list);
}

bool is_same_block(const vector<pair<int, int>>& block1, const vector<pair<int, int>>& block2) {
    if (block1.size() != block2.size()) {
        return false;
    }
    
    // 블록들의 첫 좌표를 기준으로 상대 좌표를 만들어 비교
    vector<pair<int, int>> relative_block1, relative_block2;
    
    int base_x1 = block1[0].first, base_y1 = block1[0].second;
    int base_x2 = block2[0].first, base_y2 = block2[0].second;
    
    for (const auto& cell : block1) {
        relative_block1.push_back({cell.first - base_x1, cell.second - base_y1});
    }
    for (const auto& cell : block2) {
        relative_block2.push_back({cell.first - base_x2, cell.second - base_y2});
    }
    
    sort(relative_block1.begin(), relative_block1.end());
    sort(relative_block2.begin(), relative_block2.end());
    
    return relative_block1 == relative_block2;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = table.size();
    int m = table[0].size();
    
    visited_table.assign(n, vector<bool>(m, false));  
    visited_board.assign(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && table[i][j] == 1 && table[nx][ny] == 1) {
                    graph_table[{i, j}].push_back({nx, ny});
                    graph_table[{nx, ny}].push_back({i, j});
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && game_board[i][j] == 0 && game_board[nx][ny] == 0) {
                    graph_board[{i, j}].push_back({nx, ny});
                    graph_board[{nx, ny}].push_back({i, j});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited_table[i][j] && table[i][j] == 1) {
                bfs_table(i, j);
            }
            if (!visited_board[i][j] && game_board[i][j] == 0) {
                bfs_board(i, j);
            }
        }
    }
    
    for (auto& board_block : board_blocks) {
        bool matched = false;
        for (auto it = table_blocks.begin(); it != table_blocks.end(); it++) {
            auto& table_block_list = *it;
            for (auto& table_block : table_block_list) {
                if (is_same_block(table_block, board_block)) {
                    answer += board_block.size();
                    answers.push_back(board_block);
                    matched = true;
                    break;
                }
            }
            if (matched) {
                table_blocks.erase(it);  // 여기서 'it'을 사용해 지움
                break;
            }
        }
    }
    
    return answer;
}