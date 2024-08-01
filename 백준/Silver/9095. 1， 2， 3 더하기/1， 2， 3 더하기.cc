#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n + 1] = {0};
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for (int i = 4; i < n + 1; i++){
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        cout << arr[n] << '\n';  
    }
    
    return 0;
}