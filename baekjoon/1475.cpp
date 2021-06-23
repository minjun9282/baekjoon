#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int rem = N;
    int arr[10] = {0, };
    while(true){
        arr[rem % 10] += 1;
        rem = rem / 10;
        if(rem == 0){
            break;
        }
    }
    arr[6] += arr[9];
    arr[6] = ceil((float)arr[6] / 2);
    arr[9] = 0;
    int min = 1;
    for(int j = 0; j < 10; j++){
        if(arr[j] != 0){
            if(arr[j] > min){
                min = arr[j];
            }
        }
    }
    cout << min << '\n';

    return 0;
}