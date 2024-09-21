#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> graph[626];
bool visited[626];


int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int num = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // cout << node << '\n';
        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (!visited[next]){
                q.push(next);
                visited[next] = true;
                num += 1;
            }
        }
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for (int j = 0; j < N; j++){
            v[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 1; j++){
            if (v[i][j] == 1 && v[i][j+1] == 1){
                graph[i * N + j].push_back(i * N + j + 1);
                graph[i * N + j + 1].push_back(i * N + j);
            }
        }
    }
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < N; j++){
            if (v[i][j] == 1 && v[i + 1][j] == 1){
                graph[i * N + j].push_back(i * N + N + j);
                graph[i * N + N + j].push_back(i * N + j);
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (v[i][j] != 0 && visited[i * N + j] == 0){
                int num = bfs(i * N + j);
                result.push_back(num);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }
    
    return 0;
}