#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// 전역 변수
int cartesian[101][101] = {0};  // 확장된 좌표계를 반영하여 배열 크기 조정
bool visited[101][101];         // 방문 여부를 체크할 배열 크기 조정
vector<int> length_results;     // 경로의 길이를 저장하는 벡터
map<pair<int, int>, vector<pair<int, int>>> graph;  // 그래프

// BFS 함수
void bfs(int x, int y, int itemX, int itemY) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int length = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int s = 0; s < size; s++) {
            auto [cur_x, cur_y] = q.front();
            q.pop();

            // 목표 지점에 도달하면 경로의 길이를 기록하고 반환
            if (cur_x == itemX && cur_y == itemY) {
                length_results.push_back(length);
                return;
            }

            // 현재 좌표에서 인접한 좌표들 탐색
            for (auto [nx, ny] : graph[{cur_x, cur_y}]) {
                if (!visited[nx][ny]) {  // 방문하지 않은 좌표만 탐색
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        length++;  // 경로 길이 증가
    }
}

// Solution 함수
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    // 1. 지도 위에 사각형 테두리 표시 (사각형의 모든 테두리를 1로 표시)
    for (int i = 0; i < rectangle.size(); i++){
        int left_down_x = rectangle[i][0] * 2;
        int left_down_y = rectangle[i][1] * 2;
        int right_upper_x = rectangle[i][2] * 2;
        int right_upper_y = rectangle[i][3] * 2;
        
        for (int j = left_down_x; j <= right_upper_x; j++){
            for (int k = left_down_y; k <= right_upper_y; k++){
                cartesian[j][k] = 1;  // 사각형 내부와 외곽선 모두 1로 표시
            }
        }
    }

    // 2. 사각형 내부는 0으로 설정 (각 사각형의 내부만 0으로 설정)
    for (int i = 0; i < rectangle.size(); i++){
        int left_down_x = rectangle[i][0] * 2 + 1;
        int left_down_y = rectangle[i][1] * 2 + 1;
        int right_upper_x = rectangle[i][2] * 2 - 1;
        int right_upper_y = rectangle[i][3] * 2 - 1;

        for (int j = left_down_x; j <= right_upper_x; j++){
            for (int k = left_down_y; k <= right_upper_y; k++){
                cartesian[j][k] = 0;  // 사각형 내부만 0으로 설정
            }
        }
    }

    // 3. 그래프 구성: 사각형의 외곽선을 따라 인접한 노드들을 연결
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            if (cartesian[i][j] == 1){
                // 상, 하, 좌, 우로 인접한 외곽선 연결
                if (i > 0 && cartesian[i-1][j] == 1) graph[{i, j}].push_back({i-1, j});
                if (i < 100 && cartesian[i+1][j] == 1) graph[{i, j}].push_back({i+1, j});
                if (j > 0 && cartesian[i][j-1] == 1) graph[{i, j}].push_back({i, j-1});
                if (j < 100 && cartesian[i][j+1] == 1) graph[{i, j}].push_back({i, j+1});
            }
        }
    }

    // 4. BFS 탐색: 2배 확장된 좌표 사용
    bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    answer = *min_element(length_results.begin(), length_results.end()) / 2;

    return answer;
}

int main() {
    vector<vector<int>> rectangle = {{2, 2, 5, 5}, {1, 3, 6, 4}, {3, 1, 4, 6}};
    int characterX = 1;
    int characterY = 4;
    int itemX = 6;
    int itemY = 3;
    int answer = solution(rectangle, characterX, characterY, itemX, itemY);
    cout << answer << '\n';

    return 0;
}
