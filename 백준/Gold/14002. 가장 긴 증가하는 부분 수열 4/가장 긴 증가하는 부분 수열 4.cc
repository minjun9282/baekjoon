#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    vector<int> length(N, 1);
    vector<vector<int>> result(N);
    for (int i = 0; i < N; i++) {
        result[i].push_back(arr[i]);
    }
    for(int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i] && length[i] < length[j] + 1){
                length[i] = length[j] + 1;
                result[i] = result[j];
                result[i].push_back(arr[i]);
            }
        }
    }
    auto max_val = *max_element(length.begin(), length.end());
    auto max_index = max_element(length.begin(), length.end()) - length.begin();
    cout << max_val << '\n';
    for (int i = 0; i < max_val; i++){
        cout << result[max_index][i] << ' ';
    }
    
    return 0;
}