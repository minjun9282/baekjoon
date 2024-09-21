#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void dfs(int node){
    visited[node] = true;
    cout << node << " ";
    
    for (int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if (!visited[next]){
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, V;
    cin >> N >> M >> V;
    while(M--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        sort(graph[x].begin(), graph[x].end());
        sort(graph[y].begin(), graph[y].end());
    }
    dfs(V);
    cout << '\n';
    memset(visited, false, sizeof(visited)); 
    bfs(V);
    
    return 0;
}