#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    vector<long long> arr(1000001);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < 1000001; i++){
        arr[i] = ((arr[i-3] + arr[i-2]) % 1000000009 + arr[i-1]) % 1000000009;
    }
    
    while(T--){
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
    
    return 0;
}