#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int arr[91][2];
    int N;
    cin >> N;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for (int i = 2; i <= N; i++){
        arr[i][0] = arr[i-1][0] + arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    cout << arr[N][0] + arr[N][1] << '\n';
    
    return 0;
}