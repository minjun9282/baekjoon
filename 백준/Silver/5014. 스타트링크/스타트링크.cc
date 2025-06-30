#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<int> result;

void bfs(int start, int F, int U, int D){
    queue<pair<int, int>> q;
    q.push({start, 0}); //make_pair(start, 0), pair<int, int>(start, 0) 도 가능
    visited[start] = true;
    result[start] = 0;
    
    while(!q.empty()){
        int current_floor = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if (current_floor + U <= F){
            if (!visited[current_floor+U]){
                q.push({current_floor+U, count+1});
                result[current_floor+U] = count+1;
                visited[current_floor+U] = true;
            }
        }
        if (current_floor - D >= 1){
            if (!visited[current_floor-D]){
                q.push({current_floor-D, count+1});
                result[current_floor-D] = count+1;
                visited[current_floor-D] = true;
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    // 총 F층, 스타트링크는 G층, 강호는 S층, 위로 U층 아래로 D층 갈 수 있음.
    // 1층~F층 사이에서만 이동 가능한 것
    // 강호가 위치한 층에서 D층 내려가거나 S층 올라가는걸 각각 인접한 노드로 두고 모두 다 찾아보면 됨.
    visited.resize(F+1, false);
    result.resize(F+1, -1);
    
    bfs(S, F, U, D);
    if (result[G] == -1){
        cout << "use the stairs" << '\n';
    }
    else{
        cout << result[G] << '\n';
    }
    
    return 0;
}