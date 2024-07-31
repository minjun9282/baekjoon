#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> cost(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> cost[i][j];
        }
    }
    vector<int> path(N);
    for (int i = 0;  i < N; i++){
        path[i] = i;
    }
    int min_cost = 10000001;
    do{
        int temp = 0;
        bool possible = true;
        for (int i = 0; i < N - 1; i++){
            if (cost[path[i]][path[i + 1]] == 0){
                possible = false;
            }
        }
        if (cost[path[N - 1]][path[0]] == 0){
            possible = false;
        }
        if (possible == true){
            for (int i = 0; i < N - 1; i++){
                temp += cost[path[i]][path[i + 1]];
            }
            temp += cost[path[N - 1]][path[0]];
        }
        if (possible == true && temp < min_cost){
            min_cost = temp;
        }
        
    } while (next_permutation(path.begin(), path.end()));
    cout << min_cost << '\n';
    
    return 0;
}