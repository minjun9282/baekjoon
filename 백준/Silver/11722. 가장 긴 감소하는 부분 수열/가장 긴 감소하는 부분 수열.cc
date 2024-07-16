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
        int num;
        cin >> num;
        v[i] = num;
    }
    vector<vector<int>> result(N, vector<int>(2));
    result[0][0] = 0; //v[0]이 포함되지 않는 가장 긴 부분 수열의 길이
    result[0][1] = 1; //v[0]이 포함되는 경우 가장 긴 부분 수열의 길이
    for (int i = 1; i < N; i++){
        result[i][1] = 1;
        result[i][0] = max(result[i-1][0], result[i-1][1]);
        int j = 0;
        int index = -1;
        while (j < i){
            if (v[j] > v[i]){
                index = j;
                result[i][1] = max(result[i][1], result[index][1] + 1);
            }
            j++;
        }
    }
    int max_num = max(result[N-1][0], result[N-1][1]);
    cout << max_num << '\n';

    return 0;
}