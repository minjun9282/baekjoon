#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> path;
vector<bool> visited;
vector<int> parents; //parents[i]: i번째 노드의 parents를 저장.

void dfs(int node){
    visited[node] = true;
    path.push_back(node);
    bool isRoot = true; //루트가 1일때의 총 경로 출력
    for (int next : graph[node]){
        if (!visited[next]){
            isRoot = false;
            dfs(next);
        }
    }
    if (isRoot){
        for (int i = 1; i < path.size(); i++){
            parents[path[i]] = path[i-1]; //바로 앞에 있는 값이 부모가 됨.
        }
    }
    path.pop_back();
    visited[node] = false; //다시 탐색하기 위해 방문 해제

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    graph.resize(N+1);
    visited.resize(N+1, false);
    parents.resize(N+1);
    
    int M = N - 1;
    while(M--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    for (int i = 2; i < N+1; i++){
        cout << parents[i] << '\n';
    }
    
    return 0;
}