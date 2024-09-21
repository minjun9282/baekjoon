#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> graph[10001];
bool visited[10001];

int bfs(int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 1});
    visited[start] = true;
    int num = 1;
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (node == end){
            return steps;
        }
        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (!visited[next]){
                q.push({next, steps+1});
                visited[next] = true;
            }
        }
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++){
            v[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (j < M - 1 && v[i][j] == 1 && v[i][j+1] == 1){
                graph[i * M + j].push_back(i * M + j + 1);
                graph[i * M + j + 1].push_back(i * M + j);
            }
            if (i < N - 1 && v[i][j] == 1 && v[i+1][j] == 1){
                graph[i * M + j].push_back(i * M + M + j);
                graph[i * M + M + j].push_back(i * M + j);
            }
        }
    }
    int result = bfs(N * M - 1, 0);
    cout << result << '\n';
    
    return 0;
}