#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    vector<vector<int>> result1(N, vector<int>(2)); // 앞에서부터 가장 긴 증가하는 부분 수열
    vector<vector<int>> result2(N, vector<int>(2)); // 뒤에서부터 가장 긴 증가하는 부분 수열
    result1[0][0] = 0;
    result1[0][1] = 1;
    for (int i = 1; i < N; i++){
        result1[i][1] = 1;
        result1[i][0] = max(result1[i-1][0], result1[i-1][1]);
        int j = 0;
        int index;
        while (j < i){
            if (v[j] < v[i]){
                index = j;
                result1[i][1] = max(result1[i][1], result1[j][1] + 1);
            }
            j++;
        }
    }
    result2[N-1][0] = 0;
    result2[N-1][1] = 1;
    for (int i = N - 2; i > -1; i--){
        result2[i][1] = 1;
        result2[i][0] = max(result2[i+1][0], result2[i+1][1]);
        int j = N - 1;
        int index;
        while (j > i){
            if (v[j] < v[i]){
                index = j;
                result2[i][1] = max(result2[i][1], result2[j][1] + 1);
            }
            j--;
        }
    }
    int max_result = 0;
    for (int i = 0; i < N; i++){
        int temp = 0;
        temp = result1[i][1] + result2[i][1];
        if (temp > max_result){
            max_result = temp;
        }
    }
    cout << max_result - 1 << '\n';

    return 0;
}