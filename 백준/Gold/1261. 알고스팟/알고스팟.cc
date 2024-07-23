#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> M >> N;  
    vector<vector<int>> maze(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 0;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                int new_dist = dist[x][y] + maze[nx][ny];
                if (dist[nx][ny] == -1 || new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << dist[N-1][M-1] << '\n';

    return 0;
}