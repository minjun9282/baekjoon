#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> maps;
vector<int> visited;  // 1차원 배열로 퀸 위치 저장
int result = 0;

void dfs(int N, int col) {
    if (col == N) {  // 모든 퀸을 배치 완료하면 경우의 수 증가
        result++;
        return;
    }

    for (int i = 0; i < N; i++) {  // i = 현재 열(col)에 놓을 행(row)
        bool canPlace = true;

        for (int j = 0; j < col; j++) { // 이전 열들과 충돌 검사
            if (visited[j] == i || abs(visited[j] - i) == abs(j - col)) { 
                canPlace = false;  // 같은 행 또는 대각선에 위치하면 배치 불가능
                break;
            }
        }

        if (canPlace) {
            visited[col] = i;  // 퀸 배치
            dfs(N, col + 1);   // 다음 열 탐색
            visited[col] = -1; // 백트래킹 (초기화)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    maps.resize(N, vector<int>(N));
    visited.resize(N, -1);  // -1로 초기화 (퀸이 놓이지 않은 상태)

    dfs(N, 0);
    cout << result << '\n';

    return 0;
}
