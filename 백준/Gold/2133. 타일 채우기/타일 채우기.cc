#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int arr[N+1] = {0};
    arr[0] = 1;
    arr[2] = 3;
    arr[4] = 11;
    for (int j = 5; j < N + 1; j++){
        arr[j] = arr[j-2] * 3;
        for (int k = j - 4; k >= 0; k -= 2){
            arr[j] += arr[k] * 2;
        }
    }
    cout << arr[N] << '\n';
    
    return 0;
}