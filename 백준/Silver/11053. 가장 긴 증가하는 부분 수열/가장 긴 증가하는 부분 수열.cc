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
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            if ((arr[j] < arr[i]) && (length[i] < length[j] + 1)){
                length[i] = length[j] + 1;
            }
        }
    }
    
    auto max_val = *max_element(length.begin(), length.end());
    cout << max_val << '\n';
    
    return 0;
}
