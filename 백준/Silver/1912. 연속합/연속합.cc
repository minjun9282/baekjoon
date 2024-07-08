#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> sum(n);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++){
        sum[i] = arr[i];
        if (sum[i] < sum[i-1] + arr[i]){
            sum[i] = sum[i-1] + arr[i];
        }
    }
    int result = *max_element(sum.begin(), sum.end());
    cout << result << '\n';
    
    return 0;
}