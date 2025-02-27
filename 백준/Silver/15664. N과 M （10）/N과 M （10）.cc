#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

bool visited[10001];
vector<int> inputs;
vector<int> results;
set<vector<int>> final_results; 
void dfs(vector<int> inputs, int N, int M, int count, int idx){
    if (count == M){
        final_results.insert(results);
    }
    else{
        for (int index = idx; idx < N; idx++){
            if (!visited[idx]){
                results[count] = inputs[idx];
                visited[idx] = true;
                dfs(inputs, N, M, count + 1, idx+1);
                visited[idx] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 비내림차순 수열 모두 구하기
    //1. N, M 입력 받기
    int N, M;
    cin >> N >> M;
    
    //2. N개의 수 입력 받기
    inputs.resize(N);
    results.resize(N);
    for (int i = 0; i < N; i++){
        cin >> inputs[i];
    }
    sort(inputs.begin(), inputs.end());
    // 3. 출력하기.
    dfs(inputs, N, M, 0, 0);
    for (auto iter = final_results.begin(); iter != final_results.end(); iter++){
        for (int j = 0; j < M; j++){
            cout << (*iter)[j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}