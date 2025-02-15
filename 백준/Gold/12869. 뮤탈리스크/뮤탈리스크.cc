#include <iostream>
#include <queue>
using namespace std;

struct State{
    int a, b, c, cnt; //cnt는 current 공격 횟수
};

int damage[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};
bool visited[61][61][61];

int bfs(int a, int b, int c){
    queue<State> q;
    q.push({a, b, c, 0});
    visited[a][b][c] = true;
    
    while (!q.empty()){
        State cur = q.front();
        q.pop();
        int x = cur.a;
        int y = cur.b;
        int z = cur.c;
        int cnt = cur.cnt;
        
        if (x ==0 & y ==0 && z ==0){
            return cnt;
        }
        
        for (int i = 0; i < 6; i++){
            int nx = max(0, x - damage[i][0]);
            int ny = max(0, y - damage[i][1]);
            int nz = max(0, z - damage[i][2]);
            
            if (!visited[nx][ny][nz]){
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, cnt +1});
            }
        }
    }
    return - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> scv(3, 0); //N이랑 관계없이 3개로 초기화
    for (int i = 0; i < N; i++){
        cin >> scv[i];
    }
    cout << bfs(scv[0], scv[1], scv[2]) << '\n';
    
    return 0;
}