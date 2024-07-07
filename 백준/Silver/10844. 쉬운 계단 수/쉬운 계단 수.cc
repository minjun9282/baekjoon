#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[101][10];
    int N;
    cin >> N;
    arr[1][0] = 0;
    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[1][3] = 1;
    arr[1][4] = 1;
    arr[1][5] = 1;
    arr[1][6] = 1;
    arr[1][7] = 1;
    arr[1][8] = 1;
    arr[1][9] = 1;
    for (int i = 2; i <= N; i++){
        for (int j = 0; j <= 9; j++){
            if (j == 0){
                arr[i][j] = arr[i-1][1];
            }
            else if (j == 9){
                arr[i][j] = arr[i-1][8];
            }
            else{
                arr[i][j] = ((arr[i-1][j-1] % 1000000000) + (arr[i-1][j+1] % 1000000000)) % 1000000000;
            }
        }
    }
    int result = 0;
    for (int k = 0; k <= 9; k++){
        result += arr[N][k];
        result = result % 1000000000;
    }
    cout << result << '\n';
    
    return 0;
}