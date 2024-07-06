#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int MOD = 1000000009;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    int arr[MAX_N + 1][4] = {0};
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;

    for (int i = 4; i <= MAX_N; i++){
        arr[i][1] = (arr[i-1][2] + arr[i-1][3]) % MOD;
        arr[i][2] = (arr[i-2][1] + arr[i-2][3]) % MOD;
        arr[i][3] = (arr[i-3][1] + arr[i-3][2]) % MOD;
    }

    while(T--){
        int n;
        cin >> n;
        cout << ((arr[n][1] + arr[n][2]) % MOD + arr[n][3]) % MOD << '\n';
    }
    
    return 0;
}
