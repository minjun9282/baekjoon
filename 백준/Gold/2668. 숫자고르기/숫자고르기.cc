#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[101];
bool visited[101];

vector<int> answer;
vector<int> first;
vector<int> second;

void dfs(int node) {
    visited[node] = true;
    answer.push_back(node);  
    first.push_back(node);   

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        second.push_back(next);  
        if (!visited[next]) {
            dfs(next);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> total_answer;
    for(int i = 1; i < N + 1; i++){
        int n;
        cin >> n;
        graph[i].push_back(n);
    }
    
    for(int i = 1; i < N + 1; i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        if (first == second){
            for (int val : first) {
                if (find(total_answer.begin(), total_answer.end(), val) == total_answer.end()) {
                    total_answer.push_back(val);
                }
            }

        }
        first.clear();
        second.clear();
        answer.clear();
    }
    cout << total_answer.size() << '\n';
    
    sort(total_answer.begin(), total_answer.end());
    for(int i = 0; i < total_answer.size(); i++){
        cout << total_answer[i] << '\n';
    }
    
   
    return 0;
}