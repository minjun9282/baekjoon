#include <iostream>
using namespace std;

// 같은 수를 연속해서 사용 가능
// 순서가 다르면 다른 경우의 수
// 사용한 수의 개수가 m이어야 함 -> 사용한 수 기록해야함
int main(){
    int T;
    cin >> T;
    long long arr[1001][1001] = {0};
    ///arr[n][i]: n을 1, 2, 3의 합으로 나타내는 모든 경우의 수, 단 사용한 수의 갯수 i개
    arr[1][1] = 1;
    arr[2][1] = 1;//2
    arr[2][2] = 1;//1+1
    arr[3][1] = 1;//3
    arr[3][2] = 2;//1+2, 2+1
    arr[3][3] = 1;//1+1+1
    
    /*
    // 사용한 수의 개수가 m개인 조건이 없는 경우
    for (int i = 4; i < 100001; i++){
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
    }
    */
    for (int i = 4; i < 1001; i++){
        //n이 4이상일때 arr[i][1]은 불가능.
        for (int j = 2; j < i; j++){
            arr[i][j] = (((arr[i-1][j-1] + arr[i-2][j-1]) % 1000000009)+ arr[i-3][j-1]) % 1000000009;
        }
        arr[i][i] = 1;
    }
    while(T--){
        int n, m;
        cin >> n >> m;
        cout << arr[n][m] << '\n';
    }

    return 0;
}
