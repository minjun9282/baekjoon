#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n + 1] = {0};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;
    for (int i = 3; i < n + 1; i++){
        arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
    }
    cout << arr[n] << '\n';
    
    return 0;
}