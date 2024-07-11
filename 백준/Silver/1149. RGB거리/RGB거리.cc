#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(3));
    int i = 0;
    while(i < N){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
        i++;
    }
    vector<vector<int>> result(N, vector<int>(3));
    result[0][0] = arr[0][0];
    result[0][1] = arr[0][1];
    result[0][2] = arr[0][2];
    
    for (int k = 1; k < N; k++){
        result[k][0] = min(result[k-1][1], result[k-1][2]) + arr[k][0];
        result[k][1] = min(result[k-1][0], result[k-1][2]) + arr[k][1];
        result[k][2] = min(result[k-1][0], result[k-1][1]) + arr[k][2];
    }
    cout << min({result[N-1][0], result[N-1][1], result[N-1][2]}) << '\n';
    
    return 0;
}