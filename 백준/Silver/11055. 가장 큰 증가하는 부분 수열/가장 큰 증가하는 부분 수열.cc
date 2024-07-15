#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        v[i] = num;
    }
    vector<vector<int>> result(N, vector<int>(2));
    result[0][0] = 0; //자신이 포함되지 않는 경우
    result[0][1] = v[0]; //자신이 포함되는 경우
    for (int i = 1; i < N; i++){
        result[i][0] = max(result[i-1][0], result[i-1][1]);
        result[i][1] = v[i];
        int j = 0;
        int index = -1;
        while(j < i){
            if (v[j] < v[i]){
                index = j;
                result[i][1] =  max(result[i][1], result[index][1] + v[i]);
            }
            j++;
        }
    }
    cout << max(result[N-1][0], result[N-1][1]) << '\n';
    
    return 0;
}