#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> area(N, vector<int>(M));
    int j = 0;
    while(j < N){
        for(int i = 0; i < M; i++){
            cin >> area[j][i];
        }
        j++;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (i >= 1 && j >= 1){
                area[i][j] = max(area[i-1][j], area[i][j-1]) + area[i][j];
            }
            else if (i >= 1 && j == 0){
                area[i][j] = area[i-1][j] + area[i][j];
            }
            else if (i == 0 && j >= 1){
                area[i][j] = area[i][j-1] + area[i][j];
            }
        }
    }
    cout << area[N-1][M-1] << '\n';
    
    return 0;
}