#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[9];
    for (int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    int max = arr[0];
    int max_num = 0;
    for (int j = 1; j < 9; j++){
        if(max < arr[j]){
            max = arr[j];
            max_num = j;
        }
    }
    cout << max << '\n';
    cout << (max_num + 1) << '\n';
    
    return 0;
}