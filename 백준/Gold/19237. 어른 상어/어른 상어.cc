#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct scent_map {
    int scent;
    int time_left;
};

struct current_shark_pos {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<scent_map>> scent_maps(N, vector<scent_map>(N));
    vector<current_shark_pos> current_shark_pos(M + 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp == 0) {
                scent_maps[i][j] = { 0, 0 };
            }
            else {
                scent_maps[i][j] = { temp, K };
                current_shark_pos[temp] = { i, j };
            }
        }
    }

    vector<int> current_direction(M + 1);
    for (int i = 1; i < M + 1; i++) {
        cin >> current_direction[i];
    }

    // 1:위, 2:아래, 3:왼, 4:오
    // prioritized_direction[i][1]:위쪽 향할때 우선순위
    // prioritized_direction[i][2]:아래쪽 향할때 우선순위
    // prioritized_direction[i][3]:왼쪽 향할때 우선순위
    // prioritized_direction[i][4]:오른쪽 향할때 우선순위
    vector<vector<vector<int>>> prioritized_direction(M + 1, vector<vector<int>>(5, vector<int>(5)));
    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < 5; j++) {
            for (int k = 1; k < 5; k++) {
                cin >> prioritized_direction[i][j][k];
            }
        }
    }

    // 1번 상어만 격자에 남게 되기까지 몇초가 걸리는지 시간을 구하기
    // 상어는 자신의 위치에 냄새를 뿌린 후 인접한 칸 중 하나로 이동(냄새는 K번 이후에 사라짐)
    // 1) 냄새가 비어있는 칸이 있으면 해당 칸으로 이동 - 자신이 보고 있는 방향에 따른 우선순위를 따짐
    // 2) 냄새가 비어있는 칸이 없으면 자신의 냄새가 있는 칸으로 이동 - 자신이 보고 있는 방향에 따른 우선순위를 따짐
    // 3) 모든 상어가 이동한 후 한 칸에 여러마리 상어 있으면 가장 작은 번호의 상어만 남음

    set<int> current_sharks_num;
    for (int i = 1; i < M + 1; i++) {
        current_sharks_num.insert(i);
    }

    int dx[5] = { 0, -1, 1, 0, 0 };
    int dy[5] = { 0, 0, 0, -1, 1 };
    int elapsed_time = 0;

    while (true) {
        if (current_sharks_num.size() == 1) {
            cout << elapsed_time;
            return 0;
        }
        elapsed_time++;
        if (elapsed_time > 1000) {
            cout << -1;
            return 0;
        }

        vector<pair<int, int>> next_pos(M + 1, { -1, -1 });
        vector<int> next_dir(M + 1, -1);

        // 이동 결정
        for (const auto& shark : current_sharks_num) {
            int x = current_shark_pos[shark].x;
            int y = current_shark_pos[shark].y;
            int dir = current_direction[shark];

            bool moved = false;

            // 1) 냄새 없는 칸
            for (int d = 1; d <= 4; d++) {
                int nd = prioritized_direction[shark][dir][d];
                int nx = x + dx[nd];
                int ny = y + dy[nd];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                    continue;
                }

                if (scent_maps[nx][ny].time_left == 0) {
                    next_pos[shark] = { nx, ny };
                    next_dir[shark] = nd;
                    moved = true;
                    break;
                }
            }
            // 2) 자기 냄새가 있는 칸
            if (!moved) {
                for (int d = 1; d <= 4; d++) {
                    int nd = prioritized_direction[shark][dir][d];
                    int nx = x + dx[nd];
                    int ny = y + dy[nd];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                        continue;
                    }

                    if (scent_maps[nx][ny].scent == shark && scent_maps[nx][ny].time_left > 0) {
                        next_pos[shark] = { nx, ny };
                        next_dir[shark] = nd;
                        break;
                    }
                }
            }
        }

        // 충돌 처리
        vector<vector<int>> board(N, vector<int>(N, 0));
        set<int> next_sharks;

        for (const auto& shark : current_sharks_num) {
            int nx = next_pos[shark].first;
            int ny = next_pos[shark].second;

            if (nx == -1 || ny == -1) {
                continue;
            }

            if (board[nx][ny] == 0) {
                board[nx][ny] = shark;
                next_sharks.insert(shark);
            }
            else {
                // 이미 더 작은 번호의 상어가 들어와 있으면 현재 상어는 탈락
                // 현재 shark가 더 작으면 기존 상어를 제거하고 자신이 생존
                int other_shark = board[nx][ny];

                if (other_shark < shark) {
                    continue;
                }
                else {
                    next_sharks.erase(other_shark);
                    board[nx][ny] = shark;
                    next_sharks.insert(shark);
                }
            }
        }

        // 냄새 감소
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (scent_maps[i][j].time_left > 0) {
                    scent_maps[i][j].time_left--;
                    if (scent_maps[i][j].time_left == 0) {
                        scent_maps[i][j].scent = 0;
                    }
                }
            }
        }
        // 상태 갱신
        for (const auto& shark : next_sharks) {
            current_shark_pos[shark] = { next_pos[shark].first, next_pos[shark].second };
            current_direction[shark] = next_dir[shark];
        }

        // 냄새 갱신
        for (const auto& shark : next_sharks) {
            int x = current_shark_pos[shark].x;
            int y = current_shark_pos[shark].y;
            scent_maps[x][y] = { shark, K };
        }

        current_sharks_num = next_sharks;
    }

    return 0;
}