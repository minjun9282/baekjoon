#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(10));
    for (int i = 0; i < 10; i++){
        v[0][i] = 1;
    }
    for (int j = 1; j < N; j++){
        for (int k = 0; k < 10; k++){
            for (int l = 0; l <= k; l++){
                v[j][k] += v[j-1][l];
                v[j][k] = v[j][k] % 10007;
            }
        }
    }
    int result = 0;
    for (int m = 0; m < 10; m++){
        result += v[N-1][m];
    }
    cout << result % 10007 << '\n';
    return 0;
}