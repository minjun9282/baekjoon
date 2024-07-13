#include <iostream>
using namespace std;

int arr[10001];
int result[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    arr[0] = 0;
    result[0] = 0;
    
    for (int i = 1; i < n + 1; i++){
        cin >> arr[i];
    }
    result[1] = arr[1];
    result[2] = arr[1] + arr[2];
    
    for(int j = 3; j < n + 1; j++){
        result[j] = result[j-1];
        if (result[j] < result[j-2] + arr[j]){
            result[j] = result[j-2] + arr[j];
        }
        if (result[j] < result[j-3] + arr[j-1] + arr[j]){
            result[j] = result[j-3] + arr[j-1] + arr[j];
        }
    }
    cout << result[n] << '\n';
    
    return 0;
}