#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<long long> arr(100001);
        arr[0] = 0;
        arr[1] = 1; // 1
        arr[2] = 2; // 1 + 1, 2;
        arr[3] = 4; // 1+1+1, 1+2, 2+1, 3
        for (int i = 4; i < 100001; i++){
            arr[i] = (arr[i-3] + arr[i-2] + arr[i-1]) % 1000000009;
        }
        vector<long long> answer(100001);
        answer[0] = 0;
        answer[1] = 1;
        answer[2] = 2; // 1+1, 2
        answer[3] = 2; // 1+1+1, 3
        for (int i = 4; i < 100001; i++){
            if (i % 2 == 0){
                answer[i] = (arr[i/2] + arr[i/2-1]) % 1000000009;
            }
            else{
                answer[i] = (arr[(i-1)/2] + arr[(i-3)/2]) % 1000000009;
            }
        }
    while(T--){
        int n;
        cin >> n;
        cout << answer[n] << '\n';
    }
    
    return 0;
}