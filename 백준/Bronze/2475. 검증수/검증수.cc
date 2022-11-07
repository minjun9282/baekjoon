#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5];
    int result = 0;
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
        result += (arr[i]*arr[i]);
    }
    cout << result % 10 << '\n';


    return 0;
}