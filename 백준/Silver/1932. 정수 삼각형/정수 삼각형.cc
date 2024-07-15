#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++){
        vector<int> temp(i+1);
        for (int j = 0; j < i+1; j++){
            cin >> temp[j];
        }
        v[i] = temp;
    }
    vector<vector<int>> result(n);
    result[0] = {v[0][0]};
    
    for (int i = 1; i < n; i++){
        vector<int> temp(i+1);
        for (int j = 0; j < i+1; j++){
            if (j == 0){
                temp[j] = result[i-1][0] + v[i][0];
            }
            else if (j == i){
                temp[j] = result[i-1][j-1] + v[i][j];
            }
            else{
                temp[j] = max(result[i-1][j-1], result[i-1][j]) + v[i][j];
            }
        }
        result[i] = temp;
    }
    int max = *max_element(result[n-1].begin(), result[n-1].end());
    cout << max << '\n';

    return 0;
}