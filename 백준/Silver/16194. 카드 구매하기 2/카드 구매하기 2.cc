#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N+1);
    for (int i = 1; i < N + 1; i++){
        cin >> arr[i];
    }
    vector<int> min_price(N+1, 10001);
    min_price[0] = 0;
    
    for (int i = 1; i < N + 1; i++){
        for (int j = 1; j <= i; j++){
            min_price[i] = min(min_price[i], min_price[i-j] + arr[j]);
        }
    }
    cout << min_price[N] << '\n';
    
    return 0;
}