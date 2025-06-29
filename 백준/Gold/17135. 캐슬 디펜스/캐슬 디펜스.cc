#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> maps;
vector<vector<int>> arch_pos;

// 궁수들의 위치 조합 계산
void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        arch_pos.push_back(comb);
    }
    else if (depth == arr.size())
    {
        return;
    }
    else
    {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        Combination(arr, comb, r, index, depth + 1);
    }
}

// 궁수들의 위치와 현재 맵 주어졌을 때 처치하는 적 계산
// 가장 가까운 적들 중에서도 가장 왼쪽에 있는 적
vector<vector<int>> find_enemy(vector<vector<int>> current_maps, vector<int> current_arch_pos, int D){
    int N = current_maps.size();
    int M = current_maps[0].size();
    vector<vector<int>> enemy_pos; // 처치할 적의 위치 {{x1, y1}, {x2, y2}, {x3, y3}}

    for (int arch_col : current_arch_pos) {
        int min_dist = D + 1;
        int target_row = -1;
        int target_col = -1;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (current_maps[r][c] == 1) {
                    int dist = abs(N - r) + abs(arch_col - c);
                    if (dist <= D) {
                        if (dist < min_dist || (dist == min_dist && c < target_col)) {
                            min_dist = dist;
                            target_row = r;
                            target_col = c;
                        }
                    }
                }
            }
        }

        // 궁수가 조준할 적이 있으면 위치, 없으면 {-1, -1}
        if (target_row != -1 && target_col != -1) {
            enemy_pos.push_back({target_row, target_col});
        } else {
            enemy_pos.push_back({-1, -1});
        }
    }

    return enemy_pos;
}

// 현재 맵 상태에서 적을 처치하고 적을 이동 시킴
int simulation(vector<vector<int>> current_maps, vector<int> current_arch_pos, int D){
    int N = current_maps.size();
    int M = current_maps[0].size();
    int result = 0;

    while (true) {
        vector<vector<int>> target_enemy = find_enemy(current_maps, current_arch_pos, D);
        // 같은 적 중복 제거
        vector<vector<int>> killed;
        for (auto t : target_enemy) {
            if (t[0] != -1) {
                bool dup = false;
                for (auto k : killed) {
                    if (k[0]==t[0] && k[1]==t[1]){
                        dup = true;
                        break;
                    }
                }
                if (!dup) {
                    killed.push_back(t);
                }
            }
        }
        // 적 제거
        for (auto k : killed) {
            current_maps[k[0]][k[1]] = 0;
            result++;
        }
        // 적 이동
        for (int i = N-2; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                current_maps[i+1][j] = current_maps[i][j];
            }
        }
        for (int j = 0; j < M; j++) {
            current_maps[0][j] = 0;
        }
        // 더 이상 적이 없으면 종료
        bool enemy_exist = false;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (current_maps[i][j] == 1){
                    enemy_exist = true;
                    break;
                }
            }
            if (enemy_exist) break;
        }
        if (!enemy_exist) break;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, D;
    cin >> N >> M >> D;
    maps.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> maps[i][j];
        }
    }
    
    // 궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산
    // NxM 격자판 제일 아래 행 밑에 성이 있고 궁수는 성에 배치할 수 있음.
    // 궁수는 3명 배치, 거리가 D이하(manhattan distance)인 적 중에서 가장 가까운 적/가장 왼쪽에 있는 적을 공격
    // 같은 적이 여러 궁수에게 공격당할 수 있음
    // 공격 끝나면 적이 이동: 적들은 아래로 한칸 이동 -> 성이 있는 칸(최대 행을 벗어나면 게임에서 제외됨)
    // 모든 적이 격자판에서 제외되면 게임 종료
    
    //1. 궁수가 위치할 수 있는 위치의 모든 조합 계산 (최대: 15C3)
    vector<int> numbers(M);
    for (int i = 0; i < M; i++){
        numbers[i] = i;
    }
    vector<int> comb(3);
    Combination(numbers, comb, 3, 0, 0);
    
    //2. 궁수들이 각각의 시나리오에 있을때 처치하는 적의 수 계산
    int max_result = INT_MIN;
    for (auto arch : arch_pos){
        vector<vector<int>> temp_maps = maps; // 복사본 사용
        int result = simulation(temp_maps, arch, D);
        if (result > max_result){
            max_result = result;
        }
    }
    cout << max_result << '\n';
    
    return 0;
}