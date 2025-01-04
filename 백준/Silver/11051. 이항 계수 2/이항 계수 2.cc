#include <iostream>
using namespace std;

long long arr[1001][1001] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    //초기화 nC0 = 1, nCn = 1;
    for (int i = 1; i < 1001; i++){
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for (int i = 2; i < 1001; i++){
        for (int j = 1; j <= i; j++){
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007;
        }
    }
    cout << arr[N][K] << '\n';
    
    return 0;
}