#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> t_loc; // 선생님 있는 위치 저장해두는 벡터
bool surveillance(vector<pair<int, int>> t_loc, vector<vector<char>> map){ //감시 성공시 true 리턴
    for (int i = 0; i < t_loc.size(); i++){
        int x = t_loc[i].first;
        int y = t_loc[i].second;
        for (int j = y + 1; j < map[0].size(); j++){
            if (map[x][j] == 'O'){
                break;
            }
            else if (map[x][j] == 'S'){
                return true;
            }
        }
        for (int j = y - 1; j >= 0; j--){
            if (map[x][j] == 'O'){
                break;
            }
            else if (map[x][j] == 'S'){
                return true;
            }
        }
        for (int j = x + 1; j < map.size(); j++){
            if (map[j][y] == 'O'){
                break;
            }
            else if (map[j][y] == 'S'){
                return true;;
            }
        }
        for (int j = x - 1; j >= 0; j--){
            if (map[j][y] == 'O'){
                break;
            }
            else if (map[j][y] == 'S'){
                return true;
            }
        }
    }
    
    return false;
}

bool success = false;

void dfs(int count, vector<vector<char>>& map) {
    if (count == 3) {
        if (!surveillance(t_loc, map)){
            success = true;
        }
        return;
    }

    int N = map.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'X') {
                map[i][j] = 'O';
                dfs(count + 1, map);
                map[i][j] = 'X';
                if (success) {
                    return;
                }
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 선생님(T)는 상하좌우 방향으로 감시하며 장애물로 막히기 전까지는 모두 볼 수 있음.
    // 장애물은 3개를 설치할 수 있으며 모든 학생들이 감시를 피할 수 있는지 계산
    int N;
    cin >> N;
    vector<vector<char>> map(N, vector<char>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            char input;
            cin >> input;
            map[i][j] = input;
            if (input == 'T'){
                t_loc.push_back({i, j});
            }
        }
    }
    dfs(0, map);
    cout << (success ? "YES" : "NO") << '\n';

    return 0;
}